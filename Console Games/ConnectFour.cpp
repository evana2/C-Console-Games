// Connect4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ConnectFour.h"
using namespace CN4;


int board[BOARD_HEIGHT][BOARD_WIDTH];
HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

void CN4::runConnectFour() {

	CN4::printBoard();
	while (true) {

		pair<int, int> lastPlay = CN4::userTurn(1);

		CN4::printBoard();
		if (CN4::gameOver(lastPlay)) {
			cout << "RED WINS!!";
			break;
		}

		lastPlay = CN4::userTurn(2);
		CN4::printBoard();
		if (CN4::gameOver(lastPlay)) {
			cout << "YELLOW WINSS!!";
			break;
		}
	}
}

pair<int, int> CN4::userTurn(int player) {
	if (player == 1) {
		cout << "red's turn: ";
	}
	else {
		cout << "yellow's turn: ";
	}

	int colChoice;
	cin >> colChoice;

	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "That's not a valid column, please try again: ";
			cin >> colChoice;
		}
		if (!std::cin.fail())
			break;
	}

	pair<int, int> userPlay = CN4::place(colChoice - 1, player);
	while (userPlay.first == -1) {
		cout << "That's not possible, try a different column: ";
		cin >> colChoice;

		while (1)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "That's not a valid column, please try again: ";
				cin >> colChoice;
			}
			if (!std::cin.fail())
				break;
		}
		userPlay = CN4::place(colChoice - 1, player);
	}

	return userPlay;
}

void CN4::printLine(int row) {
	int WIDTH = 4;
	int HEIGHT = WIDTH / 2;
	for (int i = 0; i < HEIGHT; i++) {
		cout << char(BLACK_SQUARE);
		for (int j = 0; j < BOARD_WIDTH; j++) {
			switch (board[row][j]) {
			case 0:
				CN4::setWhite();
				break;
			case 1:
				CN4::setRed();
				break;
			case 2:
				CN4::setYellow();
				break;
			}

			for (int k = 0; k < WIDTH; k++) {
				cout << char(COLOR_SQUARE);
			}
			cout << char(BLACK_SQUARE);
		}
		cout << "\n";
	}
	cout << "\n";
}

void CN4::printBoard() {
	cout << endl << "  1    2    3    4    5    6    7" << endl;
	for (int i = 0; i < BOARD_HEIGHT; i++) {
		CN4::printLine(i);
	}
	CN4::setWhite();
}

bool CN4::gameOver(pair<int, int> lastPlay) {
	int vertical = 1;//(|)
	int horizontal = 1;//(-)
	int diagonal1 = 1;//(\)
	int diagonal2 = 1;//(/)

	int a = lastPlay.first;
	int b = lastPlay.second;
	int player = board[a][b];

	int i;//vertical
	int ii;//horizontal
	//check for vertical(|)
	for (i = a + 1; board[i][b] == player && i <= 5; i++, vertical++);//Check down
	for (i = a - 1; board[i][b] == player && i >= 0; i--, vertical++);//Check up
	if (vertical >= 4)return true;
	//check for horizontal(-)
	for (ii = b - 1; board[a][ii] == player && ii >= 0; ii--, horizontal++);//Check left
	for (ii = b + 1; board[a][ii] == player && ii <= 6; ii++, horizontal++);//Check right
	if (horizontal >= 4) return true;
	//check for diagonal 1 (\)
	for (i = a - 1, ii = b - 1; board[i][ii] == player && i >= 0 && ii >= 0; diagonal1++, i--, ii--);//up and left
	for (i = a + 1, ii = b + 1; board[i][ii] == player && i <= 5 && ii <= 6; diagonal1++, i++, ii++);//down and right
	if (diagonal1 >= 4) return true;
	//check for diagonal 2(/)
	for (i = a - 1, ii = b + 1; board[i][ii] == player && i >= 0 && ii <= 6; diagonal2++, i--, ii++);//up and right
	for (i = a + 1, ii = b - 1; board[i][ii] == player && i <= 5 && ii >= 0; diagonal2++, i++, ii--);//up and left
	if (diagonal2 >= 4) return true;
	return false;
}

pair<int, int> CN4::place(int col, int player) {
	if (col >= 0 && col < BOARD_WIDTH)
	{
		if (board[0][col] == 0) {
			int i;
			for (i = 0; board[i][col] == 0; i++)
				if (i == 5) {
					board[i][col] = player;
					return make_pair(i, col);
				}
			i--;
			board[i][col] = player;
			return make_pair(i, col);

		}
		else {
			return make_pair(-1, col);
		}

	}
	else {
		return make_pair(-1, col);
	}

}

void CN4::setRed() {
	SetConsoleTextAttribute(out, 12);
}
void CN4::setYellow() {
	SetConsoleTextAttribute(out, 14);
}
void CN4::setWhite() {
	SetConsoleTextAttribute(out, 7);
}