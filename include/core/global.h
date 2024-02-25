/**
 * @file
 * @brief To be renamed?
*/

#ifndef GSAGB_GLOBAL_H_
#define GSAGB_GLOBAL_H_

#include "../types.h"
#include "../common.h"

#define PTR_RENDER_CONTEXT 0x17
#define PTR_RENDER_BUFFER  0x18
#define PTR_DRAW2D_1       0x1A

/**
 * @address{AGFE,02010000}
 * @address{AGSE,02010000} // FIXME: Correct address? This only shows how to add addresses for a different game
*/
extern u8 *gBuffer;

/**
 * @address{AGFE,03000000}
*/
extern void* gPtrs[64];

/**
 * @address{AGFE,03001150}
*/
extern u16 gKeyHold;

/**
 * @address{AGFE,03001154}
*/
extern u16 gKeyPress;

/**
 * @address{AGFE, 08013560}
*/
EXTERN_CALL void WaitFrames(int n);

/**
 * @address{AGFE, 08013300}
*/
EXTERN_CALL void* GetFilePtr(int fileId);

#endif // GSAGB_GLOBAL_H_