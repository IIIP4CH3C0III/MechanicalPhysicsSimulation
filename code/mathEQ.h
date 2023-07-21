// File : mathEQ.h
// This file contains the functions needed to processed to the simulation,
// The struct in here is needed to pass the arguments to a thread

#ifndef MATHEQ_H
#define MATHEQ_H

#include "objects.h"
#include "windowsMenus.h"
#include <unistd.h> //Delays
#include <math.h>
#include <pthread.h> //Threads

typedef struct // Struct to the thread
{
	WINDOW *windowStatus; 
	WINDOW *windowGraph; 
	OBJECT *objeto;
	WORLD  *world;
	GRAPH  *graph;
} ThreadArg;


// Function of the simulation
void simulation(
				WINDOW **wS , 
				WINDOW **wG , 
				OBJECT *obj , 
				WORLD  *world , 
				GRAPH  *graph
				);

// Function to do the cinematic equations
void cineEQ( 
			OBJECT *obj , 
			WORLD *world , 
			double t 
			);	

// Function to the thread of updating the status of the position,speed and acelaration
void *ThreadUpdateStatus(
						//ThreadArg *arg
						void *arg
						);

// Function to the thread to notice when the user stops the simulation or restart
void *ThreadManageProcess();

#endif
