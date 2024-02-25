/**
 * @file
 * @brief Direct Memory Access Library
*/

#ifndef GSAGB_DMA_H_
#define GSAGB_DMA_H_

#include "io.h"

static inline void DMACopy(void* dest, const void* src, u32 length) {
	register const void* r0 asm("r0") = src;
	register void*       r1 asm("r1") = dest;
	register u32         r2 asm("r2") = 0x84000000 + (length >> 2);
	register void*       r3 asm("r3") = (void*) &REG_DMA3SAD;
	asm (
	    "stmia r3!, {r0-r2}"
	 :: "r"(r0), "r"(r1), "l"(r2), "r"(r3)
	  : 
	);
}

#include "../types.h"

#endif // GSAGB_DMA_H_