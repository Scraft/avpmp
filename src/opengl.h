#ifndef AVP_OPENGL_H
#define AVP_OPENGL_H

#include "kshape.h"

void InitOpenGL();
void ThisFramesRenderingHasBegun();
void ThisFramesRenderingHasFinished();
void D3D_SkyPolygon_Output(POLYHEADER *inputPolyPtr, RENDERVERTEX *renderVerticesPtr);
void D3D_DrawBackdrop();
void D3D_FadeDownScreen(int brightness, int colour);
void RenderString(char *stringPtr, int x, int y, int colour);
void RenderStringCentred(char *stringPtr, int centreX, int y, int colour);
void D3D_DecalSystem_Setup();
void D3D_DecalSystem_End();
void SecondFlushD3DZBuffer();
void D3D_PlayerDamagedOverlay(int intensity);

#endif
