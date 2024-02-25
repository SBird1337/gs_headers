/**
 * @file
 * @brief Compression Library
*/

#ifndef GSAGB_COMPRESSION_H_
#define GSAGB_COMPRESSION_H_

#include "../common.h"

/**
 * @address{AGFE,0801587C}
*/
EXTERN_CALL void DecompressLZ(const void *src, void *dst);

#endif // GSAGB_COMPRESSION_H_