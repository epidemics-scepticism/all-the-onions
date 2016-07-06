#ifndef _ONION_H
#define _ONION_H
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint64_t u64;
/* *MUST* be called before decode will work */
void onion_value_init(void);
/* dst is 10 bytes, src is 16 bytes */
void onion_decode(u8 *dst, const u8 *src);
/* dst is 16 bytes, src is 10 bytes */
void onion_encode(u8 *dst, const u8 *src);
#endif
