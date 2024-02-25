/**
 * @file
 * @brief 2D and 3D Render Components
*/

#ifndef GSAGB_RENDER_H_
#define GSAGB_RENDER_H_

#include "../types.h"
#include "../common.h"
#include "../util/math.h"

// enums?

#define BLIT_CLEAR  1
#define BLIT_FADE   2

#define DRAW2D_BLEND_ADD   0
#define DRAW2D_BLEND_MAX   1
#define DRAW2D_BLEND_MASK  2
#define DRAW2D_BLEND_NONE  3
#define DRAW2D_FIXED      (1 << 0)
#define DRAW2D_CLIP       (1 << 1)

#define DRAW3D_TRIS_TEX_ADD  6
#define DRAW3D_TRIS_TEX      8

#define DRAW3D_CULL_NONE   0
#define DRAW3D_CULL_FRONT  1
#define DRAW3D_CULL_BACK   3

typedef void (*Draw2DFunc)(u8* dest, u8* gfx, u32 x, u32 y, u16 width, u16 height);

struct Particle {
	vector3_t pos;
	u32  _unk0C;
	u32  _unk10;
	u32  _unk14;
	u32  _unk18;
};

struct RenderContext {
	struct Particle particles[64];
	u8  buffer[28800];
	u32 blitMode;
	u32 blitParam;
	// ...
	u8  _pad[0x160];
	// ...
	u32 dirty;
};

struct Texture {
	u8  width;  // power of 2
	u8  height; // power of 2
	u16 _unk02;
	const u8* gfx;
};

struct Draw3DCommand {
	u32 cmd;
	u32 param;
	const u8* triangles;
	const fx32* vertices;
	const struct Texture* texture;
	u32 _unk14;
	u8 _unk18;
	u8 _unk19;
};

/**
 * @address{AGFE, 081435E0}
*/
EXTERN_CALL void InitAnim(u16 bgcnt);

/**
 * @address{AGFE, 08143BB8}
*/
EXTERN_CALL void EndAnim(void);

/**
 * @address{AGFE, 08157CF4}
*/
EXTERN_CALL void LoadVFXFile(int file, u8* dst, bool hasPalette, bool loadPalette);

/**
 * @address{AGFE, 08196958}
*/
EXTERN_CALL void ProjectVertices(const u8 *src, fx32 *dst, u32 vertexCount);

/**
 * @address{AGFE, 08143000}
*/
EXTERN_CALL void VFXBlitTask(void);

/**
 * @address{AGFE, 081963EC}
*/
EXTERN_CALL int BuildDraw2DFunc(int index, u32 flags);

/**
 * @address{AGFE, 08196404}
*/
EXTERN_CALL Draw2DFunc *BuildDraw2DFuncEx(int index, u32 unk1, u32 unk2, u32 flags, u32 blend);

/**
 * @address{AGFE, 081969F8}
*/
EXTERN_CALL struct Draw3DCommand *Draw3D_CreateCommandArray(u32 count);

/**
 * @address{AGFE, 08196A7C}
*/
EXTERN_CALL void Draw3D(struct Draw3DCommand *commands);

/**
 * @address{AGFE, 081991E0}
*/
extern const u8 MDL_Quad_Vertices[]; // FIXME: Count?

/**
 * @address{AGFE, 08199340}
*/
extern const u8 MDL_Quad_TrianglesUV64[]; // FIXME: Count?

#endif // GSAGB_UI_H_