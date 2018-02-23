#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include <iostream>
#include "board.h"

using namespace std;

int Board::width;
int Board::height;
char*  stor;//buffer

Board::Board()
{}

Board::Board(int w, int h){

	int i = 0;
	int j = 0;
	width = w;
	height = h;
	
	stor = new char[width*height*3];

	// glutDisplayFunc(setbackground);

	 
}

Board::~Board(){}

void Board::setpixel(char *buf, int x, int y, int r, int g, int b) { //The 3d buffer where position and colors of the pixels are stored

  buf[(y*width+x)*3+0] = r;
  buf[(y*width+x)*3+1] = g;
  buf[(y*width+x)*3+2] = b;

}

// main draw function, 
 void Board::setbackground() {
}

