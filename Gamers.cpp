#include "Gamers.h"

char Gamers::defualtName = 'A';

void Gamers::setSoldiers(Cell board[Size][Size], int gamerNum)
{
	_gamerNum = gamerNum;
	char soldierNum;
	if (gamerNum == 1) {
		soldierNum = 1;
		//name = "A";
	}
	else {
		soldierNum = 7;
		//name = "B";
	}
	int x=0, y=0, found = 0;
	for (soldier& sol : soldiers)
	{
		while (found)
		{
			y = rand() % 13 + 1;
			if (gamerNum == 2)
				x = rand() % 5 + 9;
			else
				x = rand() % 5 + 1;
			if ((board[x][y]).validToSet())
				found = 1;
		}
		//to ask how to do here cont
		sol.set(x, y, soldierNum++);
		(board[x][y]).update(gamerNum, soldierNum);
	}
}
void Gamers::setkeys(const char* keys)
{
	int i = 0;
	for (char& key : _keys)
		key = keys[i++];
}

void Gamers::notifyKeyHit(char ch)
{
	int i = 0, found = 0;
	if ((ch >= '0' && ch <= '3') || (ch >= '7' && ch <= '9'))
		//active the right soldier(stop to curr, move to new)
	
	
		if (tolower(ch) == _keys[UP])
			setDirection(Direction::UP);
		else if (tolower(ch) == _keys[DOWN])
			setDirection(Direction::DOWN);
		else if (tolower(ch) == _keys[LEFT])
			setDirection(Direction::LEFT);
		else if (tolower(ch) == _keys[RIGHT])
			setDirection(Direction::RIGHT);


}

void Gamers::setName()
{
	cin >> name;
}

void Gamers::setDirection(Direction d)
{
	//need to change the soldier according to curr soldier
	soldiers[0].setDirection(d);
}

void Gamers::printGamerName()
{
		cout << name;
}

void Gamers::printGamerScore()
{
	cout << score;
}


int Gamers::getScore()
{
	return score;
}

void Gamers::putScore(int _score)
{
	score = _score;
}