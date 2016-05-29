/*
    Copyright (C) 2016 cacahuatl < cacahuatl at autistici dot org >

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdint.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint64_t u64;

static const u8 onion_digits[33] = "abcdefghijklmnopqrstuvwxyz234567";

static u8
onion_char(u8 c)
{
	return onion_digits[c & 0x1f];
}

static void
onion_encode(const u8 *in)
{
	u8 out[17] = { 0 };
	u64 i = 0, j, x, out_sz = 0;

	while (i < 10) {
		x = 0;
		while (i < 10) {
			x |= (u64)in[i] << ((4 - i % 5) * 8);
			if (!(++i % 5)) break;
		}
		for (j = 0; j < 8; j++) {
			out[out_sz++] = onion_char(x >> (7 - j) * 5);
		}
	}
	printf("%s.onion\n", out);
}

static void
onion_next(u8 *o)
{
	u64 i = 0;
	while (i < 10) {
		if (++o[i++]) break;
	}
}

static u8
onion_done(const u8 *o)
{
	u8 r = 0;
	for (u8 i = 0; i < 10; i++) r |= o[i];
	return r;
}

int
main(void)
{
	unsigned char o[10] = { 0 };
	do {
		onion_encode(o);
		onion_next(o);
	} while (onion_done(o));
	return 0;
}
