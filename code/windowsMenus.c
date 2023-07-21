#include "windowsMenus.h"

/*
 * Function to create a window, arguments passed define the size and its location
 */
WINDOW *CreateNewWindow(int height,
						int width,
						int startRow,
						int startColumn
						)
{
	WINDOW *localWindow; //Alocate the memory necessary for the window
	localWindow = newwin( height, width, startRow, startColumn); //Create a window using the parameters 


	wrefresh( localWindow );

	box( localWindow, 0, 0); //Make a box around it with the default char in X and Y

    //wbkgd(localWindow, COLOR_PAIR(1));  // Set the background color

	return localWindow;
}

//Main menu screen
int
WindowMainMenu( )
{
	// Configure the size and location of the window
		unsigned char height = 10;  
		unsigned char width = 24;
		unsigned char row,column;
		row = (LINES - height) / 2;
		column = (COLS - width) / 2;   

	//Configure the color of the window
		//start_color();
	    //init_pair(1, COLOR_WHITE, COLOR_BLUE);  // Define the color pair for background

	WINDOW *w;
	w = CreateNewWindow( height, width, row, column );
	
	//w = newwin( height, width, row, column); //Create a window using the parameters 

    mvwprintw(w, 1, 2, "Physics Mechanics");
    mvwprintw(w, 3, 2, "1. Select Simulation");
    mvwprintw(w, 4, 2, "2. Modify Object");
    mvwprintw(w, 5, 2, "3. Modify World");
    mvwprintw(w, 6, 2, "4. Modify Graph");
    mvwprintw(w, 7, 2, "5. Quit");
    mvwprintw(w, 8, 1, " ");

	// Update the screen
	refresh(); 
	wrefresh( w );

	// Wait for a key
	int returnValue = getch();

	// Clear the window
    wclear(w);
	wrefresh( w );

	return returnValue;
}

//Simulation Menu
int
WindowSimuSelect( )
{
	// Configure the size and location of the window
		unsigned char height = 7;  
		unsigned char width = 31;
		unsigned char row,column;
		row = (LINES - height) / 2;
		column = (COLS - width) / 2;   

	//Configure the color of the window
		//start_color();
	    //init_pair(1, COLOR_WHITE, COLOR_BLUE);  // Define the color pair for background

	WINDOW *w;
	w = CreateNewWindow( height, width, row, column );
	
	//w = newwin( height, width, row, column); //Create a window using the parameters 

    mvwprintw(w, 1, 2, "Select Simulation");
    mvwprintw(w, 3, 2, "1. Constant acceleration 1D");
    //mvwprintw(w, 4, 2, "2. Constant acceleration parabolic 2D");
    mvwprintw(w, 4, 2, "5. Return");
    mvwprintw(w, 5, 1, " ");

	// Update the screen
	refresh(); 
	wrefresh( w );

	// Wait for a key
	int returnValue = getch();

	// Clear the window
    wclear(w);
	wrefresh( w );

	return returnValue;

}

int 
WindowObject( ){

	// Configure the size and location of the window
		unsigned char height = 10;  
		unsigned char width = 27;
		unsigned char row,column;
		row = (LINES - height) / 2;
		column = (COLS - width) / 2;   

	//Configure the color of the window
		//start_color();
	    //init_pair(1, COLOR_WHITE, COLOR_BLUE);  // Define the color pair for background

	WINDOW *w;
	w = CreateNewWindow( height, width, row, column );
	
    mvwprintw(w, 1, 2, "Modify Object");
    mvwprintw(w, 3, 2, "1. Initial Position");
    mvwprintw(w, 4, 2, "2. Initial Speed");
    mvwprintw(w, 5, 2, "3. Initial Accelaration");
    mvwprintw(w, 6, 2, "4. Time of Process");
    mvwprintw(w, 7, 2, "5. Return");
    mvwprintw(w, 8, 1, " ");

	// Update the screen
	refresh(); 
	wrefresh( w );

	// Wait for a key
	int returnValue = getch();

	return returnValue;
} 

int 
WindowWorld( ){

	// Configure the size and location of the window
		unsigned char height = 9;  
		unsigned char width = 35;
		unsigned char row,column;
		row = (LINES - height) / 2;
		column = (COLS - width) / 2;   

	//Configure the color of the window
		//start_color();
	    //init_pair(1, COLOR_WHITE, COLOR_BLUE);  // Define the color pair for background

	WINDOW *w;
	w = CreateNewWindow( height, width, row, column );
	
    mvwprintw(w, 1, 2, "Modify World");
    mvwprintw(w, 3, 2, "1. Reference axis");
    mvwprintw(w, 4, 2, "2. Accelaration of the gravity");
    mvwprintw(w, 5, 2, "3. Simulation step");
    mvwprintw(w, 6, 2, "5. Return");
    mvwprintw(w, 8, 1, " ");

	// Update the screen
	refresh(); 
	wrefresh( w );

	// Wait for a key
	int returnValue = getch();

	return returnValue;

}

int 
WindowGraph( )
{
		// Configure the size and location of the window
		unsigned char height = 7;  
		unsigned char width = 17;
		unsigned char row,column;
		row = (LINES - height) / 2;
		column = (COLS - width) / 2;   

	//Configure the color of the window
		//start_color();
	    //init_pair(1, COLOR_WHITE, COLOR_BLUE);  // Define the color pair for background

	WINDOW *w;
	w = CreateNewWindow( height, width, row, column );
	
    mvwprintw(w, 1, 2, "Modify graph");
    mvwprintw(w, 3, 2, "1. Graph step ");
    mvwprintw(w, 4, 2, "5. Return");
    mvwprintw(w, 5, 1, " ");

	// Update the screen
	refresh(); 
	wrefresh( w );

	// Wait for a key
	int returnValue = getch();

	return returnValue;
}

/*
 * Function to ask a value to a user, and have the values.
 * Recieve an object as a pointer, and an option that will decide which text will apear
 */
void 
getVALUEtoOBJECT( OBJECT *obj , int option )
{
	echo();

	// Configure the size and location of the window
		unsigned char height = 4;  
		unsigned char width = 60;
		unsigned char row,column;
		row = 2;
		column = (COLS - width)/2;   

	WINDOW *w;
	w = CreateNewWindow( height, width, row, column );
	box( w, 0, 0); //Make a box around it with the default char in X and Y
	
	switch( option )
	{
		case 1:
			mvwprintw(w,1,2,"Choose a value to the initial position (x,y) [m]");
			mvwprintw(w,2,2,"$ ");
				// Update the screen
					refresh(); 
					wrefresh( w );
			mvwscanw(w,2,4,"%lf,%lf", &obj->initialPosition.e_x
						   , &obj->initialPosition.e_y);
			break;
		case 2:
			mvwprintw(w,1,2,"Choose a value to the initial speed (Vx,Vy) [m/s]");
			mvwprintw(w,2,2,"$ ");
				// Update the screen
					refresh(); 
					wrefresh( w );
			mvwscanw(w,2,4,"%lf,%lf", &obj->initialSpeed.e_x
						   , &obj->initialSpeed.e_y);
			break;
		case 3:
			mvwprintw(w,1,2,"Choose a value to the initial accelaration (Ax,Ay) [m/s²]");
			mvwprintw(w,2,2,"$ ");
				// Update the screen
					refresh(); 
					wrefresh( w );
			mvwscanw(w,2,4,"%lf,%lf", &obj->initialTangentialAcceleration.e_x
						   , &obj->initialTangentialAcceleration.e_y);
			break;
		case 4:
			mvwprintw(w,1,2,"Choose the time of the event [s]");
			mvwprintw(w,2,2,"$ ");
				// Update the screen
					refresh(); 
					wrefresh( w );
			mvwscanw(w,2,4,"%lf", &obj->deltaT);
			break;

	}
	noecho();

	// Clear the window
    wclear(w);
	wrefresh( w );
	
}

void 
getVALUEtoWORLD( WORLD *wd , int option )
{
		echo();

	// Configure the size and location of the window
		unsigned char height = 4;  
		unsigned char width = 60;
		unsigned char row,column;
		row = 2;
		column = (COLS - width)/2;   

	WINDOW *w;
	w = CreateNewWindow( height, width, row, column );
	box( w, 0, 0); //Make a box around it with the default char in X and Y
	
	switch( option )
	{
		case 1:
			mvwprintw(w,1,2,"Choose the world reference (x,y)");
			mvwprintw(w,2,2,"$ ");
				// Update the screen
					refresh(); 
					wrefresh( w );
			mvwscanw(w,2,4,"%lf,%lf", &wd->reference.e_x
						   , &wd->reference.e_y);
			break;
		case 2:
			mvwprintw(w,1,2,"Choose a value to the gravity accelaration [m/s²]");
			mvwprintw(w,2,2,"$ ");
				// Update the screen
					refresh(); 
					wrefresh( w );
			mvwscanw(w,2,4,"%lf"
						   , &wd->gravity);
			break;
		case 3:
			mvwprintw(w,1,2,"Choose the simulation step [s]");
			mvwprintw(w,2,2,"$ ");
				// Update the screen
					refresh(); 
					wrefresh( w );
			mvwscanw(w,2,4,"%lf"
						   , &wd->simulationStep);
			break;

	}
	noecho();

	// Clear the window
    wclear(w);
	wrefresh( w );

}

void 
getVALUEtoGRAPH( GRAPH *g , int option )
{
		echo();

	// Configure the size and location of the window
		unsigned char height = 4;  
		unsigned char width = 60;
		unsigned char row,column;
		row = 2;
		column = (COLS - width)/2;   

	WINDOW *w;
	w = CreateNewWindow( height, width, row, column );
	box( w, 0, 0); //Make a box around it with the default char in X and Y
	
	switch( option )
	{
		case 1:
			mvwprintw(w,1,2,"Choose the step to graph, caracther equivalent to. [m]");
			mvwprintw(w,2,2,"$ ");
				// Update the screen
					refresh(); 
					wrefresh( w );
			mvwscanw(w,2,4,"%lf", &g->graphStep);
			break;
	}
	noecho();

	// Clear the window
    wclear(w);
	wrefresh( w );

}

/*
 *  STATS FUNCTION
 */
void
statusGraph( WINDOW **w )
{
	// Configure the size and location of the window
		unsigned char height = 6;  
		unsigned char width = 32;
		unsigned char row,column;
		row = 3;
		column = 3;   

	*w = CreateNewWindow( height, width, row, column );

	mvwprintw(
			 *w,
			 1,
			 width-6,
			 "s"	
			 );
	mvwprintw(
			 *w,
			 2,
			 width-6,
			 "m"	
			 );
	mvwprintw(
			 *w,
			 3,
			 width-6,
			 "m/s"	
			 );
	mvwprintw(
			 *w,
			 4,
			 width-6,
			 "m/s² "	
			 );
	
	// Update the screen
		refresh(); 
		wrefresh( *w );
}

void 
updateStatus( WINDOW **w , OBJECT *obj , double t )
{
	mvwprintw(*w,
			  1,1,
			  "%03.4lf",
			  t 
			  );	

	mvwprintw(*w,
			  2,1,
			  "%05.2lf e_x  %05.2lf e_y", 
			  obj->currentPosition.e_x,
			  obj->currentPosition.e_y
			  );	
	mvwprintw(*w,
			  3,1,
			  "%05.2lf e_x  %05.2lf e_y", 
			  obj->currentSpeed.e_x,
			  obj->currentSpeed.e_y
			  );	

	mvwprintw(*w,
			  4,1,
			  "%05.2lf e_x  %05.2lf e_y", 
			  obj->currentTangentialAcceleration.e_x,
			  obj->currentTangentialAcceleration.e_y
			  );
			  
	refresh(); 
	wrefresh( *w );
}

/*
 *  GRAPH FUNCTION
 */
void
drawGraph( WINDOW **w , GRAPH *g )
{
	// Configure the size and location of the window
		unsigned char height = LINES-5;  
		unsigned char width = COLS-5;
		unsigned char row,column;
		row = (LINES - height)/2;
		column = (COLS - width)/2;   

	*w = CreateNewWindow( height, width, row, column );
	//box( w, 0, 0); //Make a box around it with the default char in X and Y

	// Center the referencial 
		unsigned char x_axis = width/2;
		unsigned char y_axis = height/2;

	// Padding for the graph
		unsigned char padding_y = 3;
		unsigned char padding_x = 4;

	// Set the size of the absolute values of the graph, note every column and line correspond to the a singular graphStep
		g->abs_x = (width  - padding_x) * g->graphStep;
		g->abs_y = (height - padding_y) * g->graphStep;

	// Number of blocks that ocupie
		g->NumBlkX = width ;
		g->NumBlkY = height ; 

	for( int y = padding_y ; y < height - padding_y ; y++  )
		mvwaddch(
				  *w,
				  y,
				  x_axis,
				  ACS_VLINE);

	mvwaddch(
			  *w,
			  padding_y - 1,
			  x_axis,
			  ACS_UARROW);

	
	for( int x = padding_x ; x < width - padding_x ; x++)
		mvwaddch(
		 		  *w,
				  y_axis,
				  x,
				  ACS_HLINE);

	waddch(*w,ACS_RARROW);

	// Update the screen
		refresh(); 
		wrefresh( *w );
}
/*
 * POSITION THE POINT IN THE GRAPH 
 * TODO
 */
void 
updateGraph( WINDOW **w , OBJECT *obj , GRAPH *g )
{
	short int NumOfBlocksX;
	short int NumOfBlocksY = obj->currentPosition.e_y / g->graphStep;

	if( obj->currentPosition.e_x > 0 )
	{
		NumOfBlocksX = obj->currentPosition.e_x / g->graphStep; 
		NumOfBlocksX += g->NumBlkX / 2 ;  
		//NumOfBlocksX += COLS / 2; 
	}
	else if( obj->currentPosition.e_x < 0 )
	{
		NumOfBlocksX = obj->currentPosition.e_x * (-1) / g->graphStep; 
		NumOfBlocksX = g->NumBlkX / 2 - NumOfBlocksX; 
		//NumOfBlocksX = COLS / 2 - NumOfBlocksX; 
	}
	else // == 0
		NumOfBlocksX = g->NumBlkX / 2 ; //Posição inicial
		//NumOfBlocksX = COLS / 2 ; //Posição inicial		
	
	if( obj->currentPosition.e_y > 0 )
	{
		NumOfBlocksY = obj->currentPosition.e_y / g->graphStep ; //30/5 = 6 Blocos
		NumOfBlocksY = g->NumBlkY / 2 - NumOfBlocksY ; // 29/2 - 6 = 9 posição
		//NumOfBlocksY = LINES / 2 - NumOfBlocksY ; // 29/2 - 6 = 9 posição
	}
	else if( obj->currentPosition.e_y < 0 )
	{
		NumOfBlocksY = obj->currentPosition.e_y * (-1) / g->graphStep ;
		NumOfBlocksY += g->NumBlkY / 2 ; // 29/2 - 6 = 9 posição
		//NumOfBlocksY += LINES / 2 ; 
	}
	else // == 0
		NumOfBlocksY = g->NumBlkY / 2 ; //Posição inicial		
		//NumOfBlocksY = LINES / 2 ; //Posição inicial		

	mvwaddch(
			  *w,
			  NumOfBlocksY ,
			  NumOfBlocksX ,
			 'o'
			);
			
	mvprintw(
			 LINES-1,
			 1,
			  "%d_y,%d_x",NumOfBlocksY,NumOfBlocksX 
	  		 );

	// Update the screen
		refresh(); 
		wrefresh( *w );
	
}

/*
 * ADDICIONAL INFO
 */

void
additionalInfo( WINDOW **w )
{
	// Configure the size and location of the window
		unsigned char height = 5;  
		unsigned char width = 32;
		unsigned char row,column;
		row = 3;
		column = COLS - 4 - width;   

	*w = CreateNewWindow( height, width, row, column );

	mvwprintw(
			  *w,
			  1,
			  1,
			  "Simulation Stop/Start 's'/'S'"
			  );

	mvwprintw(
			  *w,
			  2,
			  1,
			  "Hide information 'h'/'H'"
			  );

	mvwprintw(
			  *w,
			  3,
			  1,
			  "Leave simulation 'Esc'"
			  );

	// Update the screen
		refresh(); 
		wrefresh( *w );
	
}
