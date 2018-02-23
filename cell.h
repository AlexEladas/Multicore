#ifndef CELL_H_
#define CELL_H_
#include <iostream>
#include <vector>
#include "board.h"
#include <thread>
using namespace std;




class Cell: public Board
{
private:
	int red;
	int green;
	int blue;
	int positionx;
	int positiony;
	bool grid[768][1024];

public:
	
	
	Cell();
	~Cell();
	static void display();
	void checkcells();
	int setcolor();
	int setpositionx();
	int setpositiony();
	int randompixels();
	void setstate();
	void clearBoard();
	void removePastState();
};

#endif

