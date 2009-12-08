//////////////////////////////////////////////////////////////////////////
//
//
//
//////////////////////////////////////////////////////////////////////////

#ifndef __GLUTAFX_H
#define __GLUTAFX_H

#include <gl/glut.h>

#pragma comment ( lib, "glut32.lib" )

#ifdef __cplusplus
extern "C" {
#endif

typedef struct tagGLUT_METHOD {
	void (*JGlutDisplay)( void );
	void (*JGlutReshape)( int width, int heigt );
	void (*JGlutKeyboard)( unsigned char key, int x, int y );
	void (*JGlutKeyArrowKey)( int key, int x, int y );
}GLUT_METHOD;

extern void JinitGLUT( GLUT_METHOD* pMethod, int argc, char** argv );

#ifdef __cplusplus
};
#endif

#endif