#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include <iostream>
#include "cell.h"
#include "board.h"
#include <time.h>
#include <thread>



Cell::Cell()//Initializes the species and posistion of each cell
{
 red = setcolor(); 

 green =  setcolor(); 

 blue =  setcolor(); 

 int random = randompixels();
 
 for(int i = 0; i<50000; i++){	
 positionx= setpositionx();
 
 positiony= setpositiony(); 

 setpixel(stor,positionx,positiony,red,green,blue);
 grid[positiony][positionx]=true;}

 display();
 
}

Cell::~Cell(){}

void Cell::checkcells(){// Computes the status of each cell
	int numalive = 0;
	bool tempGrid[768][1024];

	for (int i = 0; i < height ; i++)
	{
		for (int j = 0; j < width ; j++)
		{
		
			if ( (i+1) < height)

				if(grid[i + 1][j] == true)
				{
				
					numalive++;
				}

			if ( (i-1) >= 0)

				if(grid[i - 1][j] == true)
				{
					numalive++;
				}

			if ( (j+1) < width)
				if(grid[i][j+1] == true)
				{
					numalive++;
				}

			if ( (j-1) >= 0)
				if(grid[i][j-1] == true)
				{
					numalive++;
				}

			if ( (i+1) < height && (j+1) < width)

				if(grid[i+1][j+1] == true)
				{
					numalive++;
				}

			if ( (i+1) < height && (j-1) >= 0)

				if(grid[i+1][j-1] == true)
				{
					numalive++;
				}

			if ( (i-1) >= 0 && (j+1) < width)

				if(grid[i-1][j+1] == true)
				{
					numalive++;
				}

			if ( (i-1) >= 0 && (j-1) >= 0)

				if(grid[i-1][j-1] == true)
				{
					numalive++;
				}
			
			if (numalive < 2 || numalive > 3)
			{
				tempGrid[i][j] = false;
			

			}
			else if (numalive == 2)
			{
				tempGrid[i][j] = grid[i][j];
				

			}
			else if (numalive == 3)
			{
				tempGrid[i][j] = true;
			

			}
			
			numalive = 0;
			
		}
	}
	
	for (int i = 0; i < height ; i++)
	{
		for (int j = 0; j < width ; j++)
		{
		grid[i][j]=tempGrid[i][j];
		
		}
	}

	}



int Cell::setcolor(){

	int r = rand() % 150 + 1; 
	return r;
}

int Cell::setpositionx(){

	int x = rand() % width; 
	return x;
}

int Cell::setpositiony(){

	int y = rand() % height; 
	return y;
}

int Cell::randompixels(){//Computes a random number of initial pixels

	int y = rand() % 1000000+100000; 
	return y;
}

void Cell::display(){
glDrawPixels(width, height, GL_RGB, GL_UNSIGNED_BYTE, stor);
glutSwapBuffers();
}

void Cell::setstate(){// Sets and displays the next state
	
for (int i = 0; i < height ; i++)
	{
		for (int j = 0; j < width ; j++)
		{
			if(grid[i][j] == true){
				setpixel(stor,j,i,red,green,blue);}
			
		
		}
	}



}
void Cell::removePastState(){

	for (int i = 0; i < height ; i++)
	{
		for (int j = 0; j < width ; j++)
		{
			if(grid[i][j] == false)
				
				setpixel(stor,j,i,210,210,210);
		
		}
	}
}

void Cell::clearBoard(){

	for (int i = 0; i < height ; i++)
	{
		for (int j = 0; j < width ; j++)
		{
			
				setpixel(stor,j,i,210,210,210);
		
		}
	}

}
