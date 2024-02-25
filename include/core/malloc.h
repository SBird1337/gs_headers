/**
 * @file
 * @brief Memory Allocation Library
*/

#ifndef GSAGB_MALLOC_H_
#define GSAGB_MALLOC_H_

#include "../common.h"
#include "../types.h"

/**
 * @address{AGFE,08014D78}
*/
EXTERN_CALL void Alloc_IRAM(u32 n);

/**
 * @address{AGFE,0801314C}
*/
EXTERN_CALL void Free(const void *memory);

/**
 * @address{AGFE,08014D78}
*/
EXTERN_CALL void FreeGlobal(int index);

#endif // GSAGB_MALLOC_H_