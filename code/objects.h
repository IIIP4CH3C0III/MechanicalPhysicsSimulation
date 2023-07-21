// STRUCTS this file contains structs from the object it self, the world and graph caracteristics
// objects.h

#ifndef OBJECTS_H
#define OBJECTS_H

typedef struct //Simple struct that defines the axes of each value
{
	double e_x;
	double e_y;
	//double e_z;

	//future should contain the angle
}
axis;

typedef struct 
{
	//Initial data
	axis initialPosition;
	axis initialSpeed;	
	axis initialTangentialAcceleration;
	axis initialCentrifugeAcceleration;

	//Time maximum that the process will take, prevent to be forever running
	double deltaT;

	//Current data
	axis currentPosition;
	axis currentSpeed;	
	axis currentTangentialAcceleration;
	axis currentCentrifugeAcceleration;

} 
OBJECT;

typedef struct
{
	//How the graph should be scaled
	double graphStep;
	double abs_x;
	double abs_y;
	// double abs_z;

	//Number of "pixels" ocupies depeding on the graphStep
	short int NumBlkX;
	short int NumBlkY;
}
GRAPH;

typedef struct 
{
	//How the world should be scaled
	axis reference;
	double gravity;
	double simulationStep;
}
WORLD;

#endif 
