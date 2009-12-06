
#ifndef _FREETYPEEX_H
#define _FREETYPEEX_H

#ifdef __cplusplus

extern "C" {

#include <stdio.h>
#include <string.h>
#include <math.h>

#include <ft2build.h>
#include FT_FREETYPE_H


#define WIDTH   160
#define HEIGHT  120

void draw_bitmap( FT_Bitmap* bitmap, FT_Int x, FT_Int y);

void show_image( void );

};

#endif	// __cplusplus

#endif	// _FREETYPEEX_H