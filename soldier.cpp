#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "soldier.h"


void soldier::gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	cout.flush();
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}

void soldier::move()
{
	_x = _x + _x_dir;
	_y = _y + _y_dir;
	//TBD


}

void soldier::setDirection(Direction d)
{
	switch (d)
	{
	case Direction::UP:
		_x_dir = 0;
		_y_dir = -1;
		break;
	case Direction::DOWN:
		_x_dir = 0;
		_y_dir = 1;
		break;
	case Direction::LEFT:
		_x_dir = -1;
		_y_dir = 0;
		break;
	case Direction::RIGHT:
		_x_dir = 1;
		_y_dir = 0;
		break;
	}
}

void soldier::stop()
{
	_x_dir = 0;
	_y_dir = 0;
}

void soldier::set(int x, int y, char ch)
{
	_x = x;
	_y = y;
	_ch = ch;
}

void soldier::draw(char ch)
{
	gotoxy(_x, _y);
	cout << ch;
	cout.flush();
}
