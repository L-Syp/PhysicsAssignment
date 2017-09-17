#ifndef UNIVERSE_H
#define UNIVERSE_H
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const int MAX_BODIES_NUMBER = 5; //assumption that no more than 5 bodies will be provided
const int DIMENSION = 100;  //100x100 grid
const float SIZE = 5; //5 AU universe
const int GRAVITATIONAL_CONSTANT = 1;
const float GRID_SIZE = SIZE / (float) DIMENSION;


struct Body
{
	float x, y, mass; //data from a text file
};

struct Cell
{
	float fPotential[MAX_BODIES_NUMBER]; //gravitational impact of each body
	float fNetPotential;

	void CalculateNetPotential()
	{
		for (int i = 0; i < MAX_BODIES_NUMBER; i++)
		{
			fNetPotential += fPotential[i];
		}
	}	

	Cell() //setting all potentials to zero to get rid of the random values
	{
		for (int i = 0; i < MAX_BODIES_NUMBER; i++)
		{
			fPotential[i] = 0.0;
		}
		fNetPotential = 0.0;
	}
};

float CalculatePointPotential(float x, float y, Body body)
{
	//calculate the distance between a point and a body
	float fDistance = sqrt(pow(body.x - x * GRID_SIZE, 2) + pow(body.y - y * GRID_SIZE, 2));

	//calculate the potential V = -G*m/distance
	float fPotential;
	if (fDistance == 0.0) //to avoid division by zero
		fPotential = 0.0;
	else				
	fPotential = -((GRAVITATIONAL_CONSTANT * body.mass) / fDistance);

	return fPotential;
}

#endif