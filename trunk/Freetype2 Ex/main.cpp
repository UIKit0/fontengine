
#include "freetypeEx.h"
#include "GLUT/JglutAfx.h"

void display()
{
	static GLfloat rtri = 0.0f;
	static GLfloat rquad = 0.0f;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();									// Reset The Current Modelview Matrix
	glPushMatrix();
	glTranslatef(-1.5f,0.0f,-6.0f);						// Move Left 1.5 Units And Into The Screen 6.0
	glRotatef(rtri,0.0f,1.0f,0.0f);				// Rotate The Triangle On The Y axis
	glBegin(GL_TRIANGLES);								// Drawing Using Triangles
	glColor3f(1.0f,0.0f,0.0f);						// Set The Color To Red
	glVertex3f( 0.0f, 1.0f, 0.0f);					// Top
	glColor3f(0.0f,1.0f,0.0f);						// Set The Color To Green
	glVertex3f(-1.0f,-1.0f, 0.0f);					// Bottom Left
	glColor3f(0.0f,0.0f,1.0f);						// Set The Color To Blue
	glVertex3f( 1.0f,-1.0f, 0.0f);					// Bottom Right
	glEnd();											// Finished Drawing The Triangle

	glLoadIdentity();					// Reset The Current Modelview Matrix
	glTranslatef(1.5f,0.0f,-6.0f);				// Move Right 1.5 Units And Into The Screen 6.0
	glRotatef(rquad,1.0f,0.0f,0.0f);			// Rotate The Quad On The X axis
	glColor3f(0.5f,0.5f,1.0f);							// Set The Color To Blue One Time Only
	glBegin(GL_QUADS);									// Draw A Quad
	glVertex3f(-1.0f, 1.0f, 0.0f);					// Top Left
	glVertex3f( 1.0f, 1.0f, 0.0f);					// Top Right
	glVertex3f( 1.0f,-1.0f, 0.0f);					// Bottom Right
	glVertex3f(-1.0f,-1.0f, 0.0f);					// Bottom Left
	glEnd();											// Done Drawing The Quad
	glPopMatrix();
	rtri+=0.2f;						// Increase The Rotation Variable For The Triangle ( NEW )
	rquad-=0.15f;						// Decrease The Rotation Variable For The Quad     ( NEW )

	glutSwapBuffers ( );
}

void reshape( int w, int h )   // Create The Reshape Function (the viewport)
{
	glViewport     ( 0, 0, w, h );
	glMatrixMode   ( GL_PROJECTION );  // Select The Projection Matrix
	glLoadIdentity ( );                // Reset The Projection Matrix
	if ( h==0 )  // Calculate The Aspect Ratio Of The Window
		gluPerspective ( 80, ( float ) w, 1.0, 5000.0 );
	else
		gluPerspective ( 80, ( float ) w / ( float ) h, 1.0, 5000.0 );
	glMatrixMode   ( GL_MODELVIEW );  // Select The Model View Matrix
	glLoadIdentity ( );    // Reset The Model View Matrix
}

void keyboard( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
	case 27:        // When Escape Is Pressed...
		exit ( 0 );   // Exit The Program
		break;        // Ready For Next Case
	default:        // Now Wrap It Up
		break;
	}
}

void arrow_keys( int a_keys, int x, int y )  // Create Special Function (required for arrow keys)
{
	switch ( a_keys ) {
	case GLUT_KEY_UP:     // When Up Arrow Is Pressed...
		glutFullScreen ( ); // Go Into Full Screen Mode
		break;
	case GLUT_KEY_DOWN:               // When Down Arrow Is Pressed...
		glutReshapeWindow ( 500, 500 ); // Go Into A 500 By 500 Window
		break;
	default:
		break;
	}
}
int main()
{
	int argc = 1;
	char* argv[] = { "test", "" };

	JGLUT_METHOD method;

	method.JGlutDisplay = display;
	method.JGlutReshape = reshape;
	method.JGlutKeyboard = keyboard;
	method.JGlutKeyArrowKey = arrow_keys;

	JinitGLUT( &method, argc, argv );

	FT_Library    library;
	FT_Face       face;

	FT_GlyphSlot  slot;
	FT_Matrix     matrix;                 /* transformation matrix */
	FT_Vector     pen;                    /* untransformed origin  */
	FT_Error      error;

	char*         filename;
	char*         text;

	double        angle;
	int           target_height;
	int           n, num_chars;

	filename      = "c:/windows/fonts/malgun.ttf";                           /* first argument     */
	text          = "Test";                           /* second argument    */
	num_chars     = strlen( text );
	angle         = 25;//( 25.0 / 360 ) * 3.14159 * 2;      /* use 25 degrees     */
	target_height = HEIGHT;

	error = FT_Init_FreeType( &library );              /* initialize library */
	/* error handling omitted */

	error = FT_New_Face( library, filename, 0, &face ); /* create face object */
	/* error handling omitted */

	/* use 50pt at 100dpi */
	error = FT_Set_Char_Size( face, 50 * 64, 0,
		100, 0 );                /* set character size */
	/* error handling omitted */

	slot = face->glyph;

	/* set up matrix */
	matrix.xx = (FT_Fixed)( cos( angle ) * 0x10000L );
	matrix.xy = (FT_Fixed)(-sin( angle ) * 0x10000L );
	matrix.yx = (FT_Fixed)( sin( angle ) * 0x10000L );
	matrix.yy = (FT_Fixed)( cos( angle ) * 0x10000L );

	/* the pen position in 26.6 cartesian space coordinates; */
	/* start at (300,200) relative to the upper left corner  */
	pen.x = 30 * 64;
	pen.y = ( target_height - 110 ) * 64;

	glutMainLoop();
	FT_Done_Face    ( face );
	FT_Done_FreeType( library );

	return 0;

	for ( n = 0; n < num_chars; n++ )
	{
		/* set transformation */
		FT_Set_Transform( face, &matrix, &pen );

		/* load glyph image into the slot (erase previous one) */
		error = FT_Load_Char( face, text[n], FT_LOAD_RENDER );
		if ( error )
			continue;                 /* ignore errors */

		/* now, draw to our target surface (convert position) */
		draw_bitmap( &slot->bitmap,
			slot->bitmap_left,
			target_height - slot->bitmap_top );

		/* increment pen position */
		pen.x += slot->advance.x;
		pen.y += slot->advance.y;
	}

	show_image();

	FT_Done_Face    ( face );
	FT_Done_FreeType( library );

	return 0;
}

/* EOF */
