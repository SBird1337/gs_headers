/**
 * @file
 * @brief Fixed Point Math and 3D Math Library
*/

#ifndef GSAGB_MATH_H_
#define GSAGB_MATH_H_

#include "../types.h"
#include "../common.h"

#define FX(f) ((fx32)((f) * 0x10000))

typedef struct {
    fx32 x, y, z;
} vector3_t;

typedef vector3_t matrix_t[4];

/**
 * @address{AGFE, 03000478}
*/
extern matrix_t gMatrix;

/**
 * @address{AGFE, 0300021C}
*/
EXTERN_CALL fx32 FixedMultiply(fx32 a, fx32 b);

/**
 * @address{AGFE, 03000230}
*/
EXTERN_CALL fx32 FixedDivide(fx32 a, fx32 b);

/**
 * @address{AGFE, 08002096}
*/
EXTERN_CALL fx32 FixedSine(u16 theta);

/**
 * @address{AGFE, 08002090}
*/
EXTERN_CALL fx32 FixedCosine(u16 theta);

/**
 * @address{AGFE, 08014DE4}
*/
EXTERN_CALL void LoadIdentityMatrix(void);

/**
 * @address{AGFE, 08015068}
*/
EXTERN_CALL void MatrixYaw(u16 angle);

/**
 * @address{AGFE, 08015024}
*/
EXTERN_CALL void MatrixPitch(u16 angle);

/**
 * @address{AGFE, 080150E4}
*/
EXTERN_CALL void MatrixRoll(u16 angle);

/**
 * @address{AGFE, 0801521C}
*/
EXTERN_CALL void MatrixScale(fx32 scaleFactor);

#endif // GSAGB_MATH_H_