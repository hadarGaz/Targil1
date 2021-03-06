
#include "GameManeger.h"

using namespace std;


void GameManeger::menu()
{
	bool getout = false;
	while (!getout)
	{
		cout << "1. Choose names for gamers" << endl;
		cout << "2. Start game" << endl;
		cout << "3. Start opisite game" << endl;
		cout << "4. Reset score" << endl;
		cout << "9. Exit" << endl;
		char userchoise;
		cin >> userchoise;
		switch (userchoise)
		{
		case '1':
			cout << "Choose name for the fisrt gamer" << endl;
			gamers[0].setName();
			cout << "Choose name for the second gamer" << endl;
			gamers[1].setName();
			break;
		case '2':
			startGame();
			break;
		case '3':
			clearScreen();
			swapScore();
			break;
		case '4':
			resetScore();
			cout << "Score was reset";
			break;
		case '9':
			getout = true;
			break;
		default:
			cout << "Unsupported option.." << endl;
		}

	}


}
void GameManeger::startGame()
{
	int gamerNum = 1;
	gamers[0].setSoldiers(board, gamerNum++);
	gamers[1].setSoldiers(board, gamerNum);
	run();
}
void GameManeger::run()
{
	char ch =0;
	bool flag = 0;
	clearScreen();
	printBoard();
	gamers[0].drowSoldiers();
	gamers[1].drowSoldiers();
	while (ch != ESC)
	{
		if (flag == 0)
		{
			gamers[0].move(board);
			//����� �� ���� ����
			flag = 1;
		}
		else
		{
			gamers[1].move(board);
			//����� �� ���� ����
			flag = 0;
		}
		Sleep(80);
		if (_kbhit())
		{
			ch = getch();
			gamers[0].notifyKeyHit(ch);
			gamers[1].notifyKeyHit(ch);
		}
	}
	clearScreen();
	//stop the game
	seconderyMenu();
}

void GameManeger::printBoard()
{
	char flag = 166;
	int typeofcell;
	int num = 1;
	printLetters();
	printEndLine();
	for (int i = 1; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			cout << "|";
			if (j == 0)
				printNumber(num++);
			else {
				typeofcell = board[i][j].returnedCellType();
				if (typeofcell == empty) {
					cout << "   ";
				}
				else if (typeofcell == fr) {
					cout << "FR ";
				}
				else if (typeofcell == sea) {
					cout << "SEA";
				}
				else if (typeofcell == flagA) {
					cout << " " << flag << "A";
				}
				else {
					cout << " " << flag << "B";
				}
			}
		}
		cout << "|" << endl;
		printEndLine();
	}
	cout << "SCORE: " << endl;
	for (int i = 0; i < SizeOfSoldier; i++) {
		cout << "Gamer: ";
		gamers[i].printGamerName();
		cout << " = ";
		gamers[i].printGamerScore();
		cout << endl;
	}

}



void GameManeger::setBoard()
{
	board[7][1].setCellType(fr);
	board[8][1].setCellType(fr);
	board[7][2].setCellType(fr);
	board[4][3].setCellType(fr);
	board[5][3].setCellType(fr);
	board[6][3].setCellType(fr);
	board[7][3].setCellType(fr);
	board[6][4].setCellType(fr);
	board[7][4].setCellType(fr);
	board[8][4].setCellType(fr);
	board[9][4].setCellType(fr);

	board[6][8].setCellType(sea);
	board[5][9].setCellType(sea);
	board[6][9].setCellType(sea);
	board[4][10].setCellType(sea);
	board[5][10].setCellType(sea);
	board[6][10].setCellType(sea);
	board[7][10].setCellType(sea);
	board[8][10].setCellType(sea);
	board[9][10].setCellType(sea);
	board[10][10].setCellType(sea);
	board[7][11].setCellType(sea);
	board[8][11].setCellType(sea);
	board[9][11].setCellType(sea);
	board[8][12].setCellType(sea);

	board[1][11].setCellType(flagA);
	board[13][2].setCellType(flagB);

}

void GameManeger::printLetters()
{
	char ch = 'A';
	cout << "|" << "   ";
	for (int p = 1; p<Size; p++)
		cout << "| " << ch++ << " ";
	cout << "|" << endl;
}

void GameManeger::printEndLine()
{
	for (int l = 0; l < Size; l++)
		cout << "====";
	cout << endl;
}


void GameManeger::printNumber(int num)
{
	
	if (num >= 10)
		cout << " " << num;
	else
		cout << " " << num << " ";
}

void GameManeger::swapScore()
{
	int scoreA = gamers[0].getScore();
	int scoreB = gamers[1].getScore();
	gamers[0].putScore(scoreA);
	gamers[1].putScore(scoreB);
}

void GameManeger::seconderyMenu()
{
	bool getout = false;
	while (!getout)
	{
		cout << "1. Return to game " << endl;
		cout << "2. Start new game" << endl;
		cout << "8. Go to the main menu" << endl;
		cout << "9. Exit" << endl;
		char userchoise;
		cin >> userchoise;
		switch (userchoise)
		{
		case '1':
			run();
			break;
		case '2':
			startGame();
			break;
		case '8':
			clearScreen();
			menu();
			break;
		case '9':
			getout = true;
			break;
		default:
			cout << "Unsupported option.." << endl;
		}

	}
}

void GameManeger::resetScore()
{
	for (Gamers& gamer : gamers)
		gamer.putScore(0);
}

