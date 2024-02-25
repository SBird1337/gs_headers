/**
 * @file
 * @brief Compression Library
*/

#ifndef GSAGB_SOUND_H_
#define GSAGB_SOUND_H_

#include "../types.h"
#include "../common.h"

/**
 * @address{AGFE,081C0CB0}
*/
EXTERN_CALL void PlaySound(u16 soundId);

#endif // GSAGB_SOUND_H_