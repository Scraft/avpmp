#ifndef OGLFUNC_H
#define OGLFUNC_H

#if defined(_MSC_VER)
#include <windows.h>
#endif

#if defined(_PANDORA)
#	include "gl.h"
#	define _GL_STATIC	// Use Nano GL...
#else
#	include <GL/gl.h>
#endif
//#include <GL/glext.h>

#if defined(_GL_STATIC)

#	define pglPixelStorei	glPixelStorei
#	define pglReadPixels	glReadPixels
#	define pglViewport		glViewport
#	define pglMatrixMode	glMatrixMode
#	define pglLoadIdentity	glLoadIdentity
#	define pglEnable		glEnable
#	define pglBlendFunc		glBlendFunc
#	define pglDepthFunc		glDepthFunc
#	define pglDepthMask		glDepthMask
#	define pglDisable		glDisable
#	define pglClear			glClear
#	define pglHint			glHint
#	define pglGetString		glGetString
#	define pglAlphaFunc		glAlphaFunc
#	define pglTexParameteri	glTexParameteri
#	define pglBindTexture	glBindTexture
#	define pglEnableClientState		glEnableClientState
#	define pglDisableClientState	glDisableClientState
#	define pglVertexPointer		glVertexPointer
#	define pglTexCoordPointer	glTexCoordPointer
#	define pglColorPointer		glColorPointer
#	define pglGenTextures		glGenTextures
#	define pglTexImage2D		glTexImage2D
#	define pglTexEnvi			glTexEnvi
#	define pglDeleteTextures		glDeleteTextures
#	define pglPolygonOffset			glPolygonOffset
#	define pglColor4ub				glColor4ub
#	define pglVertex3f				glWrapperVertex3f
#	define pglBegin					glWrapperBegin
#	define pglEnd					glWrapperEnd
#	define pglArrayElement			glWrapperArrayElement
#	define pglTexCoord2f			glWrapperTexCoord2f
#	define pglColor4f				glColor4f
#	define pglClearColor			glClearColor
#	define pglPushAttrib			glWrapperPushAttrib
#	define pglPopAttrib				glWrapperPopAttrib
#	define pglPixelZoom				glWrapperPixelZoom
#	define pglPushMatrix			glPushMatrix
#	define pglPopMatrix				glPopMatrix
#	define pglOrtho					glWrapperOrtho
#	define pglRasterPos2i			glWrapperRasterPos2i
#	define pglDrawPixels			glWrapperDrawPixels
#	define pglGetError				glGetError
#	define pglPopClientAttrib		glWrapperPopClientAttrib
#	define pglTexSubImage2D			glTexSubImage2D

void glWrapperVertex3f( float x, float y, float z );
void glWrapperBegin( GLenum mode );
void glWrapperEnd( );
void glWrapperArrayElement( GLint i );
void glWrapperTexCoord2f( GLfloat s, GLfloat t );
void glWrapperPushAttrib( );
void glWrapperPopAttrib( );
void glWrapperPixelZoom( GLfloat xFactor, GLfloat yFactor );
void glWrapperOrtho( GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near_val, GLdouble far_val );
void glWrapperRasterPos2i( GLint x, GLint y );
void glWrapperDrawPixels( GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels );
void glWrapperPushClientAttrib( GLbitfield mask);
void glWrapperPopClientAttrib( );

#else

typedef void (APIENTRY *PFNGLALPHAFUNCPROC)(GLenum, GLclampf);
typedef void (APIENTRY *PFNGLARRAYELEMENTPROC)(GLint);
typedef void (APIENTRY *PFNGLBEGINPROC)(GLenum);
typedef void (APIENTRY *PFNGLBINDTEXTUREPROC)(GLenum, GLuint);
typedef void (APIENTRY *PFNGLBLENDFUNCPROC)(GLenum, GLenum);
typedef void (APIENTRY *PFNGLCLEARPROC)(GLbitfield);
typedef void (APIENTRY *PFNGLCLEARCOLORPROC)(GLclampf, GLclampf, GLclampf, GLclampf);
typedef void (APIENTRY *PFNGLCOLOR3FPROC)(GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLCOLOR3FVPROC)(const GLfloat *);
typedef void (APIENTRY *PFNGLCOLOR3UBPROC)(GLubyte, GLubyte, GLubyte);
typedef void (APIENTRY *PFNGLCOLOR3UBVPROC)(const GLubyte *);
typedef void (APIENTRY *PFNGLCOLOR4FPROC)(GLfloat, GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLCOLOR4FVPROC)(const GLfloat *);
typedef void (APIENTRY *PFNGLCOLOR4UBPROC)(GLubyte, GLubyte, GLubyte, GLubyte);
typedef void (APIENTRY *PFNGLCOLOR4UBVPROC)(const GLubyte *);
typedef void (APIENTRY *PFNGLCOLORPOINTERPROC)(GLint, GLenum, GLsizei, const GLvoid *);
typedef void (APIENTRY *PFNGLCULLFACEPROC)(GLenum);
typedef void (APIENTRY *PFNGLDELETETEXTURESPROC)(GLsizei,const GLuint*);
typedef void (APIENTRY *PFNGLDEPTHFUNCPROC)(GLenum);
typedef void (APIENTRY *PFNGLDEPTHMASKPROC)(GLboolean);
typedef void (APIENTRY *PFNGLDEPTHRANGEPROC)(GLclampd, GLclampd);
typedef void (APIENTRY *PFNGLDISABLEPROC)(GLenum);
typedef void (APIENTRY *PFNGLDISABLECLIENTSTATEPROC)(GLenum);
typedef void (APIENTRY *PFNGLDRAWBUFFERPROC)(GLenum);
typedef void (APIENTRY *PFNGLDRAWELEMENTSPROC)(GLenum, GLsizei, GLenum, const GLvoid *);
typedef void (APIENTRY *PFNGLDRAWPIXELSPROC)(GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
typedef void (APIENTRY *PFNGLDRAWRANGEELEMENTSPROC)(GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid *);
typedef void (APIENTRY *PFNGLENABLEPROC)(GLenum);
typedef void (APIENTRY *PFNGLENABLECLIENTSTATEPROC)(GLenum);
typedef void (APIENTRY *PFNGLENDPROC)(GLvoid);
typedef void (APIENTRY *PFNGLFRONTFACEPROC)(GLenum);
typedef void (APIENTRY *PFNGLFRUSTUMPROC)(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLGENTEXTURESPROC)(GLsizei,GLuint*);
typedef GLenum (APIENTRY *PFNGLGETERRORPROC)(void);
typedef void (APIENTRY *PFNGLGETFLOATVPROC)(GLenum, GLfloat *);
typedef void (APIENTRY *PFNGLGETINTEGERVPROC)(GLenum, GLint *);
typedef const GLubyte* (APIENTRY *PFNGLGETSTRINGPROC)(GLenum);
typedef void (APIENTRY *PFNGLHINTPROC)(GLenum, GLenum);
typedef void (APIENTRY *PFNGLLOADIDENTITYPROC)(void);
typedef void (APIENTRY *PFNGLLOADMATRIXFPROC)(const GLfloat *);
typedef void (APIENTRY *PFNGLMATRIXMODEPROC)(GLenum);
typedef void (APIENTRY *PFNGLMULTMATRIXFPROC)(const GLfloat *);
typedef void (APIENTRY *PFNGLNORMALPOINTERPROC)(GLenum, GLsizei, const GLvoid *);
typedef void (APIENTRY *PFNGLORTHOPROC)(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLPIXELSTOREIPROC)(GLenum, GLint);
typedef void (APIENTRY *PFNGLPIXELZOOMPROC)(GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLPOLYGONMODEPROC)(GLenum, GLenum);
typedef void (APIENTRY *PFNGLPOLYGONOFFSETPROC)(GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLPOPATTRIBPROC)(void);
typedef void (APIENTRY *PFNGLPOPCLIENTATTRIBPROC)(void);
typedef void (APIENTRY *PFNGLPOPMATRIXPROC)(void);
typedef void (APIENTRY *PFNGLPUSHATTRIBPROC)(GLbitfield);
typedef void (APIENTRY *PFNGLPUSHCLIENTATTRIBPROC)(GLbitfield);
typedef void (APIENTRY *PFNGLPUSHMATRIXPROC)(void);
typedef void (APIENTRY *PFNGLRASTERPOS2IPROC)(GLint, GLint);
typedef void (APIENTRY *PFNGLREADBUFFERPROC)(GLenum);
typedef void (APIENTRY *PFNGLREADPIXELSPROC)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLvoid *);
typedef void (APIENTRY *PFNGLROTATEFPROC)(GLfloat, GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLSCALEFPROC)(GLfloat,GLfloat,GLfloat);
typedef void (APIENTRY *PFNGLSHADEMODELPROC)(GLenum);
typedef void (APIENTRY *PFNGLTEXCOORD2FPROC)(GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLTEXCOORD2FVPROC)(const GLfloat *);
typedef void (APIENTRY *PFNGLTEXCOORD3FPROC)(GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLTEXCOORD3FVPROC)(const GLfloat *);
typedef void (APIENTRY *PFNGLTEXCOORD4FPROC)(GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLTEXCOORD4FVPROC)(const GLfloat *);
typedef void (APIENTRY *PFNGLTEXCOORDPOINTERPROC)(GLint, GLenum, GLsizei, const GLvoid *);
typedef void (APIENTRY *PFNGLTEXENVFPROC)(GLenum, GLenum, GLfloat);
typedef void (APIENTRY *PFNGLTEXENVFVPROC)(GLenum, GLenum, const GLfloat *);
typedef void (APIENTRY *PFNGLTEXENVIPROC)(GLenum, GLenum, GLint);
typedef void (APIENTRY *PFNGLTEXIMAGE2DPROC)(GLenum,GLint,GLint,GLsizei,GLsizei,GLint,GLenum,GLenum,const GLvoid*);
typedef void (APIENTRY *PFNGLTEXPARAMETERFPROC)(GLenum, GLenum, GLfloat);
typedef void (APIENTRY *PFNGLTEXPARAMETERIPROC)(GLenum, GLenum, GLint);
typedef void (APIENTRY *PFNGLTEXSUBIMAGE2DPROC)(GLenum,GLint,GLint,GLint,GLsizei,GLsizei,GLenum,GLenum,const GLvoid*);
typedef void (APIENTRY *PFNGLTRANSLATEFPROC)(GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLVERTEX2FPROC)(GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLVERTEX2FVPROC)(const GLfloat *);
typedef void (APIENTRY *PFNGLVERTEX3FPROC)(GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLVERTEX3FVPROC)(const GLfloat *);
typedef void (APIENTRY *PFNGLVERTEX4FPROC)(GLfloat, GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLVERTEX4FVPROC)(const GLfloat *);
typedef void (APIENTRY *PFNGLVERTEXPOINTERPROC)(GLint, GLenum, GLsizei, const GLvoid *);
typedef void (APIENTRY *PFNGLVIEWPORTPROC)(GLint, GLint, GLsizei, GLsizei);

#if defined(_PANDORA)
typedef void (APIENTRY * PFNGLCOLORTABLEEXTPROC) (GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const GLvoid *table);
typedef void (APIENTRY * PFNGLGETCOLORTABLEEXTPROC) (GLenum target, GLenum format, GLenum type, GLvoid *data);
typedef void (APIENTRY * PFNGLGETCOLORTABLEPARAMETERIVEXTPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRY * PFNGLGETCOLORTABLEPARAMETERFVEXTPROC) (GLenum target, GLenum pname, GLfloat *params);
#endif

#if defined(_MSC_VER) || defined(_PANDORA)
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3BEXTPROC) (GLbyte red, GLbyte green, GLbyte blue);
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3BVEXTPROC) (const GLbyte *v);
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3DEXTPROC) (GLdouble red, GLdouble green, GLdouble blue);
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3DVEXTPROC) (const GLdouble *v);
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3FEXTPROC) (GLfloat red, GLfloat green, GLfloat blue);
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3FVEXTPROC) (const GLfloat *v);
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3IEXTPROC) (GLint red, GLint green, GLint blue);
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3IVEXTPROC) (const GLint *v);
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3SEXTPROC) (GLshort red, GLshort green, GLshort blue);
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3SVEXTPROC) (const GLshort *v);
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3UBEXTPROC) (GLubyte red, GLubyte green, GLubyte blue);
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3UBVEXTPROC) (const GLubyte *v);
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3UIEXTPROC) (GLuint red, GLuint green, GLuint blue);
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3UIVEXTPROC) (const GLuint *v);
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3USEXTPROC) (GLushort red, GLushort green, GLushort blue);
typedef void (APIENTRY * PFNGLSECONDARYCOLOR3USVEXTPROC) (const GLushort *v);
typedef void (APIENTRY * PFNGLSECONDARYCOLORPOINTEREXTPROC) (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
#endif

extern PFNGLALPHAFUNCPROC		pglAlphaFunc;
extern PFNGLARRAYELEMENTPROC		pglArrayElement;
extern PFNGLBEGINPROC			pglBegin;
extern PFNGLBINDTEXTUREPROC		pglBindTexture;
extern PFNGLBLENDFUNCPROC		pglBlendFunc;
extern PFNGLCLEARPROC			pglClear;
extern PFNGLCLEARCOLORPROC		pglClearColor;
extern PFNGLCOLOR3FPROC		pglColor3f;
extern PFNGLCOLOR3UBPROC		pglColor3ub;
extern PFNGLCOLOR3UBVPROC		pglColor3ubv;
extern PFNGLCOLOR4FPROC		pglColor4f;
#if !defined(_PANDORA)
extern PFNGLCOLOR3FVPROC		pglColor3fv;
extern PFNGLCOLOR4FVPROC		pglColor4fv;
extern PFNGLTEXCOORD2FVPROC		pglTexCoord2fv;
extern PFNGLTEXCOORD3FPROC		pglTexCoord3f;
extern PFNGLTEXCOORD3FVPROC		pglTexCoord3fv;
extern PFNGLTEXCOORD4FPROC		pglTexCoord4f;
extern PFNGLTEXCOORD4FVPROC		pglTexCoord4fv;
extern PFNGLVERTEX2FPROC		pglVertex2f;
extern PFNGLVERTEX2FVPROC		pglVertex2fv;
extern PFNGLVERTEX4FPROC		pglVertex4f;
extern PFNGLVERTEX4FVPROC		pglVertex4fv;
extern PFNGLPOLYGONMODEPROC		pglPolygonMode;
extern PFNGLDRAWBUFFERPROC		pglDrawBuffer;
extern PFNGLDRAWRANGEELEMENTSPROC	pglDrawRangeElements;
extern PFNGLREADBUFFERPROC		pglReadBuffer;
extern PFNGLDEPTHRANGEPROC		pglDepthRange;
extern PFNGLVERTEX3FVPROC		pglVertex3fv;
#endif
extern PFNGLCOLOR4UBPROC		pglColor4ub;
extern PFNGLCOLOR4UBVPROC		pglColor4ubv;
extern PFNGLCOLORPOINTERPROC		pglColorPointer;
extern PFNGLCULLFACEPROC		pglCullFace;
extern PFNGLDELETETEXTURESPROC		pglDeleteTextures;
extern PFNGLDEPTHFUNCPROC		pglDepthFunc;
extern PFNGLDEPTHMASKPROC		pglDepthMask;
extern PFNGLDISABLEPROC		pglDisable;
extern PFNGLDISABLECLIENTSTATEPROC	pglDisableClientState;
extern PFNGLDRAWELEMENTSPROC		pglDrawElements;
extern PFNGLDRAWPIXELSPROC		pglDrawPixels;
extern PFNGLENABLEPROC			pglEnable;
extern PFNGLENABLECLIENTSTATEPROC	pglEnableClientState;
extern PFNGLENDPROC			pglEnd;
extern PFNGLFRONTFACEPROC		pglFrontFace;
extern PFNGLFRUSTUMPROC		pglFrustum;
extern PFNGLGENTEXTURESPROC		pglGenTextures;
extern PFNGLGETERRORPROC		pglGetError;
extern PFNGLGETFLOATVPROC		pglGetFloatv;
extern PFNGLGETINTEGERVPROC		pglGetIntegerv;
extern PFNGLGETSTRINGPROC		pglGetString;
extern PFNGLHINTPROC			pglHint;
extern PFNGLLOADIDENTITYPROC		pglLoadIdentity;
extern PFNGLLOADMATRIXFPROC		pglLoadMatrixf;
extern PFNGLMATRIXMODEPROC		pglMatrixMode;
extern PFNGLMULTMATRIXFPROC		pglMultMatrixf;
extern PFNGLNORMALPOINTERPROC		pglNormalPointer;
extern PFNGLORTHOPROC			pglOrtho;
extern PFNGLPIXELSTOREIPROC		pglPixelStorei;
extern PFNGLPIXELZOOMPROC		pglPixelZoom;
extern PFNGLPOLYGONOFFSETPROC		pglPolygonOffset;
extern PFNGLPOPATTRIBPROC		pglPopAttrib;
extern PFNGLPOPCLIENTATTRIBPROC		pglPopClientAttrib;
extern PFNGLPOPMATRIXPROC		pglPopMatrix;
extern PFNGLPUSHATTRIBPROC		pglPushAttrib;
extern PFNGLPUSHCLIENTATTRIBPROC	pglPushClientAttrib;
extern PFNGLPUSHMATRIXPROC		pglPushMatrix;
extern PFNGLRASTERPOS2IPROC		pglRasterPos2i;
extern PFNGLREADPIXELSPROC		pglReadPixels;
extern PFNGLROTATEFPROC		pglRotatef;
extern PFNGLSCALEFPROC			pglScalef;
extern PFNGLSHADEMODELPROC		pglShadeModel;
extern PFNGLTEXCOORD2FPROC		pglTexCoord2f;
extern PFNGLTEXCOORDPOINTERPROC	pglTexCoordPointer;
extern PFNGLTEXENVFPROC		pglTexEnvf;
extern PFNGLTEXENVFVPROC		pglTexEnvfv;
extern PFNGLTEXENVIPROC		pglTexEnvi;
extern PFNGLTEXIMAGE2DPROC		pglTexImage2D;
extern PFNGLTEXPARAMETERFPROC		pglTexParameterf;
extern PFNGLTEXPARAMETERIPROC		pglTexParameteri;
extern PFNGLTEXSUBIMAGE2DPROC		pglTexSubImage2D;
extern PFNGLTRANSLATEFPROC		pglTranslatef;
extern PFNGLVERTEX3FPROC		pglVertex3f;
extern PFNGLVERTEXPOINTERPROC		pglVertexPointer;
extern PFNGLVIEWPORTPROC		pglViewport;

// GL_EXT_paletted_texture
extern PFNGLCOLORTABLEEXTPROC			pglColorTableEXT;
extern PFNGLGETCOLORTABLEPARAMETERIVEXTPROC	pglGetColorTableParameterivEXT;

// GL_EXT_secondary_color
extern PFNGLSECONDARYCOLOR3FEXTPROC		pglSecondaryColor3fEXT;
extern PFNGLSECONDARYCOLOR3FVEXTPROC		pglSecondaryColor3fvEXT;
extern PFNGLSECONDARYCOLOR3UBEXTPROC		pglSecondaryColor3ubEXT;
extern PFNGLSECONDARYCOLOR3UBVEXTPROC		pglSecondaryColor3ubvEXT;
extern PFNGLSECONDARYCOLORPOINTEREXTPROC	pglSecondaryColorPointerEXT;

#endif

extern int ogl_have_paletted_texture;
extern int ogl_have_secondary_color;

extern int ogl_use_paletted_texture;
extern int ogl_use_secondary_color;

extern void load_ogl_functions(int mode);
extern int check_for_errors(const char *file, int line);

#endif
