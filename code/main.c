#include "windowsMenus.h"
#include "objects.h"
#include "mathEQ.h"

int 
main()
{
	// Configure some basic information to the cursus
		initscr(); //Start the cursus terminal
		noecho();  //Hide the char insert
		keypad(stdscr, TRUE); //Enable special keys
		//raw(); //Disable special combinations, like Ctrl+C
		cbreak(); 

	//Menu aux variables
	char 			optionChoosen = 'n';
	unsigned char 	returnMenu;

	//Struct variables
	WINDOW 	*PointerWgraph;
	WINDOW 	*PointerWstats;
	WINDOW 	*PointerWinfo;

	OBJECT 	object;
	GRAPH 	graph;
	WORLD 	world;

	//Other usefull variables
		//none

	
	while( optionChoosen != 'Y' && optionChoosen != 'y' )
	{
		clear(); //Clear everythign in screen
		versionText();
		optionChoosen = (int)WindowMainMenu(); //Get the option from the menu 
		returnMenu = 0; //Confirmation value
		
			switch(optionChoosen) //Option choosed from the menu
			{
				default: //Invalid options
					mvprintw(0,0,"Invalid choice. Please try again.\n");
					getch();
					break;
					
				case '1': //Window for the simulation
					mvprintw(0,0,"Selected WindowSimuSelected\n");
					while( returnMenu == 0 )
					{

						unsigned char simulationChoosed = WindowSimuSelect( );

						switch(simulationChoosed)
						{
							default:
								mvprintw(0,0,"Invalid choice. Please try again.\n");
								getch();
								break;
								
							case '1': //constant movement 
								(void)drawGraph( &PointerWgraph , &graph );
								(void)statusGraph( &PointerWstats ); 
								(void)additionalInfo( &PointerWinfo );
							
								(void)simulation( &PointerWstats , &PointerWgraph  , &object , &world , &graph );

								break;
							case '5': //Back
								returnMenu = 1;
								break;
						}
					}//end while					
					break;
						
				case '2':
					mvprintw(0,0,"Selected WindowObject\n");

					while( returnMenu == 0 )
					{
						unsigned char editOption = WindowObject( );
						
						switch( editOption )
						{
							default:
								mvprintw(0,0,"Invalid choice. Please try again.\n");
								getch();
								break;
							case '1': //Initial Position
								(void)getVALUEtoOBJECT( &object , 1 );
								break;
							case '2': //Initial Speed
								(void)getVALUEtoOBJECT( &object , 2 );
								break;
							case '3': //Initial Acc
								(void)getVALUEtoOBJECT( &object , 3 );
								break;
							case '4': //Time
								(void)getVALUEtoOBJECT( &object , 4 );
								break;
							case '5':
								returnMenu = 1;
								break;
						}
					}//end while
					break;
					
				case '3':
					mvprintw(0,0,"Selected WindowWorld\n");

					while( returnMenu == 0 )
					{
						unsigned char editOption = WindowWorld( );

						switch( editOption )
						{
							default:
								mvprintw(0,0,"Invalid choice. Please try again.\n");
								getch();
								break;
							case '1': //Initial Position
								(void)getVALUEtoWORLD( &world , 1 );
								break;
							case '2': //Initial Speed
								(void)getVALUEtoWORLD( &world , 2 );
								break;
							case '3': //Initial Acc
								(void)getVALUEtoWORLD( &world , 3 );
								break;
							case '5':
								returnMenu = 1;
								break;
						}
					}//end while

					break;

				case '4':
					mvprintw(0,0,"Selected WindowGraph\n");

					while( returnMenu == 0 )
					{
						unsigned char editOption = WindowGraph( );

						switch( editOption )
						{
							default:
								mvprintw(0,0,"Invalid choice. Please try again.\n");
								getch();
								break;
							case '1': //Graph Step
								(void)getVALUEtoGRAPH( &graph , 1 );
								break;
							case '5':
								returnMenu = 1;
								break;
						}
					}//end while

					break;

				case '5':
					mvprintw(0,0,"Confirm exit program (Y/N)\n");
					optionChoosen = getch();
					break;
			}//end switch
	}//end while
	
	// Terminate the curses 
		endwin();	

	return 0;
}

