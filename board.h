#ifndef BOARD_H_
#define BOARD_H_
#include <iostream>
#include <vector>

using namespace std;
extern char *stor;
class Board
{

private:
public:
	static int width;
	static int height;
	//static char *stor;
	vector<vector<bool>>grid;
	Board();
	Board(int, int);
	~Board();
	static void setbackground();
	static void setpixel(char*,int,int,int,int,int);


};

#endif
