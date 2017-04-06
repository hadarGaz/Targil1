#include "Cell.h"

bool Cell::validToSet()
{
	if (this->cellType == emptyType && this->GamerA == noGamerA && this->GamerB == noGamerB)
		return true;
	else
		return false;
}

void Cell::update(int gamerNum, int soldierNum)
{
	if (gamerNum == 1)
		GamerA = soldierNum;
	else
		GamerB = soldierNum;
}

void Cell::setCellType(int num)
{
	this->cellType = num;
}

int Cell::returnedCellType()
{
	return this->cellType;

}