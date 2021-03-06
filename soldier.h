#pragma once
//#include "Gamers.h"
#include "Direction.h"
#include <cstdlib>
#include <iostream>
#include "Utils.h"
#include "Cell.h"
using namespace std;

class soldier {
	enum Type { emptyType, sea, fr, flagA, flagB };
	enum GamerA { noGamerA, soldier1, soldier2, soldier3 };
	enum GamerB { noGamerB, soldier7 = 7, soldier8 = 8, soldier9 = 9 };
	enum { MIN_X = 1, MAX_X = 13, MIN_Y = 1, MAX_Y = 13 };
	enum { Size = 14 };
	int _x, _y;
	int _x_dir =0, _y_dir=0;
	int soldierNum;
	int seaPass = 0;
	int frPass = 0;
	void draw(int ch);
	friend class Gamers;
public:
	//soldier() {}
	//soldier(int x, int y, char ch) : _x(x) , _y(y),_ch(ch) {}
	void set(int x, int y, int ch);
	//void setChar();
	void draw() { draw(soldierNum); }
	void earse() { draw(' '); }
	void move(Cell board[Size][Size]);
	void move();
	void setDirection(Direction d);
	void stop();
	void setCondition(int soldierNum);

};
