#include "freetypeEx.h"

/* origin is the upper left corner */
unsigned char image[HEIGHT][WIDTH];


/* Replace this function with something useful. */

void
draw_bitmap( FT_Bitmap*  bitmap,
			FT_Int      x,
			FT_Int      y)
{
	FT_Int  i, j, p, q;
	FT_Int  x_max = x + bitmap->width;
	FT_Int  y_max = y + bitmap->rows;


	for ( i = x, p = 0; i < x_max; i++, p++ )
	{
		for ( j = y, q = 0; j < y_max; j++, q++ )
		{
			if ( i < 0      || j < 0       ||
				i >= WIDTH || j >= HEIGHT )
				continue;

			image[j][i] |= bitmap->buffer[q * bitmap->width + p];
		}
	}
}


void
show_image( void )
{
	int  i, j;


	FILE *f = NULL;

	f = fopen("out.txt", "w" );

	if ( f == NULL ) {
		printf(" file open error\n" );
	}

	for ( i = 0; i < HEIGHT; i++ )
	{
		for ( j = 0; j < WIDTH; j++ ) {
			fputc( image[i][j] == 0 ? ' '
				: image[i][j] < 128 ? '+'
				: '*', f );
		}
		fputc( '\n', f );
		// 			putchar( image[i][j] == 0 ? ' '
		// 			: image[i][j] < 128 ? '+'
		// 			: '*' );
		//		putchar( '\n' );
	}

	fclose( f );

	printf(" out.txt print complete\n" );
}

/* EOF */
