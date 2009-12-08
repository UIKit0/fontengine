//////////////////////////////////////////////////////////////////////////
//
//
//
//////////////////////////////////////////////////////////////////////////

#include "JglutAfx.h"

void _JinitGLUT()
{
	glShadeModel( GL_SMOOTH );							// Enable Smooth Shading
	glClearColor( 0.0f, 0.0f, 0.0f, 0.5f );				// Black Background
	glClearDepth( 1.0f );									// Depth Buffer Setup
	glEnable( GL_DEPTH_TEST );							// Enables Depth Testing
	glDepthFunc( GL_LEQUAL );								// The Type Of Depth Testing To Do
	glEnable( GL_COLOR_MATERIAL );
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
}

//////////////////////////////////////////////////////////////////////////
// Function Name: JinitGLUT()
// In: GLUT_METHOD Pointer
// Out: void
// Explanation:
//		이 함수는 GLUT를 초기화 하는 함수 이다.
//		GLUT 콜백 함수에서 필요로 하는 사용자 지정 함수를
//		구조체 포인터에 담아서 인자로 넘겨 받는다.
void JinitGLUT( GLUT_METHOD* pMethod, int argc, char** argv )
{
	glutInit( &argc, argv );
	_JinitGLUT();
}