#include "mathEQ.h"

volatile int leave, stop; //A global variable that is updated using volatile syntax in every thread at the same time

void *ThreadUpdateStatus(void *arg) 
{
    ThreadArg *args = (ThreadArg *)arg; // Get the information from the argument in format ThreadArg
	WINDOW *wS = args->windowStatus;
	WINDOW *wG = args->windowGraph;
	OBJECT *obj = args->objeto;
	WORLD *world = args->world;
	GRAPH *g = args->graph;

	double t = 0.0;
	
	updateGraph( &wG , obj , g); //update the position in the graph
	while( leave == 0 && t < obj->deltaT )
		while( stop == 0 && t < obj->deltaT )
		{
			t += world->simulationStep; // Increment the time, like the user wanted, lower better
			cineEQ( obj , world ,  t );  // Do the cinematic equations
			
			updateStatus ( &wS , obj , t );  // Update the information on the screen
			updateGraph( &wG , obj , g); //update the position in the graph

			sleep(1); //simulation RealTime

		}
	
	    pthread_exit(NULL);
}

void *ThreadManageProcess()
{	
	char local = ' ';
	stop = 0;  
	leave = 0;

	while( local != '\033' )
	{
		local = getch();

		if( local == 's' || local == 'S' )
		{
			if (stop == 1)
				stop = 0;
			else
				stop = 1;
		}
			

		if( local == '\033' )
			leave = 1;
	}

    pthread_exit(NULL);
}


void cineEQ( OBJECT *obj , WORLD *world , double t )	
{
	if( obj->initialTangentialAcceleration.e_x != 0 && obj->initialTangentialAcceleration.e_y == 0 ) //1D movement, need to be changed after
	{
		obj->currentPosition.e_x = obj->initialPosition.e_x + obj->initialSpeed.e_x * t + 0.5 * pow(t,2) * obj->initialTangentialAcceleration.e_x;   
		obj->currentSpeed.e_x = obj->initialSpeed.e_x + t * obj->initialTangentialAcceleration.e_x;   
	}
	if( obj->initialTangentialAcceleration.e_x == 0 && obj->initialTangentialAcceleration.e_y == 0 ) //2D movement (parabolic) , need to be changed after
	{
		obj->currentPosition.e_x = obj->initialPosition.e_x + obj->initialSpeed.e_x * t ;   
		obj->currentSpeed.e_x = obj->initialSpeed.e_x ;   
		obj->currentPosition.e_y = obj->initialPosition.e_y + obj->initialSpeed.e_y * t - 0.5 * pow(t,2) * world->gravity ;   
		obj->currentSpeed.e_y = obj->initialSpeed.e_y + t * world->gravity;   
	}
}



//Function to start the simulation at what are its rules
void simulation(
				WINDOW **wS , 
				WINDOW **wG , 
				OBJECT *obj , 
				WORLD  *world ,
				GRAPH  *graph
				)
{
	obj->currentPosition.e_x = obj->initialPosition.e_x ;
	obj->currentPosition.e_y = obj->initialPosition.e_y ;
	obj->currentSpeed.e_x = obj->initialSpeed.e_x ;
	obj->currentSpeed.e_y = obj->initialSpeed.e_y ;
	obj->currentTangentialAcceleration.e_x = obj->initialTangentialAcceleration.e_x ;
	obj->currentTangentialAcceleration.e_y = obj->initialTangentialAcceleration.e_y ;

	pthread_t loopThread, inputThread;

   ThreadArg args = {*wS, *wG, obj, world, graph};

    if (pthread_create(&loopThread, NULL, ThreadUpdateStatus, &args ) != 0) {
        // fprintf(stderr, "Failed to create count thread.\n");
        // return 1;
    }

    if (pthread_create(&inputThread, NULL, ThreadManageProcess, NULL) != 0) {
        // fprintf(stderr, "Failed to create count thread.\n");
        // return 1;
    }

	
    // Wait for the count thread to finish
    if (pthread_join(loopThread, NULL) != 0) {
       // fprintf(stderr, "Failed to join count thread.\n");
       // return 1;
    }

    // Wait for the input thread to finish
    if (pthread_join(inputThread, NULL) != 0) {
       // fprintf(stderr, "Failed to join input thread.\n");
       // return 1;
    }
}
