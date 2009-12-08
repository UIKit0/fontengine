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
//		�� �Լ��� GLUT�� �ʱ�ȭ �ϴ� �Լ� �̴�.
//		GLUT �ݹ� �Լ����� �ʿ�� �ϴ� ����� ���� �Լ���
//		����ü �����Ϳ� ��Ƽ� ���ڷ� �Ѱ� �޴´�.
void JinitGLUT( GLUT_METHOD* pMethod, int argc, char** argv )
{
	glutInit( &argc, argv );
	_JinitGLUT();
}