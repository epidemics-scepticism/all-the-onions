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
#include "onion.h"

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
	for (u8 i = 0; i < 10; i++)
		if (o[i]) return o[i];
	return 0;
}

int
main(void)
{
	u8 o[17] = { 0 }, i[10] = { 0 };
	do {
		onion_encode(o, i);
		printf("%s.onion\n", (char *)o);
		onion_next(i);
	} while (onion_done(i));
	return 0;
}
