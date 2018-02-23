#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include <iostream>
#include "board.h"
#include "cell.h"
#include <time.h>
#include <thread>
#include<vector>
#include <algorithm> 
#include <Windows.h>
#include "tbb\include\tbb\parallel_for.h"





int getrandom()
{
	return rand() % 10+5; 
}

void do_join(std::thread& t)
{
    t.join();
}

void join_all(vector<std::thread>& v)
{
    std::for_each(v.begin(),v.end(),do_join);
}

int main(int argc, char **argv) {
	srand ( time(NULL) );

	vector<thread>computation;
	int numspecies = getrandom();// Random number of species


  // initialize the glut system and create a window
	glutInitWindowSize(1024, 768);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutCreateWindow("Game of Life");
   
	Board b(1024,768);

	Cell *cells=new Cell[numspecies];// Initializes number of species

	Sleep(1000);// Makes the program wait 1 second so the initial positions can be observed

	cells[0].clearBoard();
	
	while(1)
	{
		cells[0].clearBoard();

		tbb::parallel_for(0, numspecies,1,[=] (int u) {
			cells[u].checkcells();
		});
		
		for( int u = 0; u<numspecies; u++)
		{
			
			cells[u].setstate();
	
			Sleep(30);  //Run the computation threads every 0.03 seconds
		}
		glDrawPixels(1024, 768, GL_RGB, GL_UNSIGNED_BYTE, stor);

		glutSwapBuffers();

 
	computation.clear();// Clears the vector since the threads are being called in a loop

	}
 glutMainLoop();
}