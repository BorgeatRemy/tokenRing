#ifndef _RESOURCES_MANAGER_H
#define _RESOURCES_MANAGER_H

#include "gfx.h"

// Image indexes
#define token_w 0
#define token 1

// Font indexes
#define arial__14 0
#define arial_12 1

#ifdef __cplusplus
extern "C" {
#endif

	bool_t guiResourcesManagerInit(void);
	gdispImage* gstudioGetImage(int imageIndex);
	const char* gstudioGetImageFilePath(int imageIndex);
	font_t gstudioGetFont(int fontIndex);

#ifdef __cplusplus
}
#endif

#endif // _RESOURCES_MANAGER_H
