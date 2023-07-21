#ifndef WINDOWSMENUS_H
#define WINDOWSMENUS_H

#include <ncurses.h>
#include "objects.h"

WINDOW *CreateNewWindow(int height, int width, int startRow, int startColumn);

int WindowMainMenu( );
int WindowSimuSelect( );
int WindowObject( );
int WindowWorld( );
int WindowGraph( );

void getVALUEtoOBJECT( OBJECT *obj , int option );
void getVALUEtoWORLD( WORLD *wd , int option );
void getVALUEtoGRAPH( GRAPH *g , int option );

void statusGraph( WINDOW **w );
void drawGraph( WINDOW **w , GRAPH *g );
void additionalInfo( WINDOW **w );

void updateStatus( WINDOW **w , OBJECT *obj , double t );
void updateGraph( WINDOW **w , OBJECT *obj , GRAPH *g );

#endif
