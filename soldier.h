#pragma once
//#include "Gamers.h"
#include "Direction.h"
#include <cstdlib>
#include <iostream>

using namespace std;

class soldier {
	enum { MIN_X = 1, MAX_X = 13, MIN_Y = 1, MAX_Y = 13 };
	int _x, _y;
	int _x_dir =1, _y_dir=0;
	char _ch;
	void draw(char ch);
public:
	soldier() {}
	soldier(int x, int y, char ch) : _x(x) , _y(y),_ch(ch) {}
	void set(int x, int y, char ch);
	//void setChar();
	void gotoxy(int x, int y);
	void draw() { draw(_ch); }
	void earse() { draw(' '); }
	void move();
	void setDirection(Direction d);
	void stop();

};
