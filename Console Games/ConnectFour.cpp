// Connect4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ConnectFour.h"
using namespace CN4;


int board[BOARD_HEIGHT][BOARD_WIDTH];
HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

void CN4::runConnectFour() {

	//TODO SELECT NUM PLAYERS
	cout << "Do you have 1 or 2 players? ";
	int playerCount;
	cin >> playerCount;

	while (1)
	{
		if (cin.fail() || !(playerCount == 1 || playerCount == 2))
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "That's not a valid number, please try again: ";
			cin >> playerCount;
		}
		if (!std::cin.fail() && (playerCount == 1 || playerCount == 2)) {
			break;
		}
	}

	CN4::clearBoard();
	CN4::printBoard();

	if (playerCount == 1) {
		CN4::onePlayer();
	} else {
		CN4::twoPlayer();
	}
	
}

void CN4::clearBoard() {
	for (int i = 0; i < BOARD_HEIGHT; i++) {
		for (int j = 0; j < BOARD_WIDTH; j++) {
			board[i][j] = 0;
		}
	}
}

void CN4::onePlayer() {

	//TODO CHOOSE DIFFICULTY LEVEL
	int difficulty = 1;


	while (true) {
		pair<int, int> lastPlay = CN4::userTurn(1);
		CN4::printBoard();
		if (CN4::gameOver(lastPlay, 1)) {
			cout << "YOU WIN\n";
			break;
		}

		lastPlay = CN4::computerTurn(2, difficulty);
		CN4::printBoard();
		if (CN4::gameOver(lastPlay, 2)) {
			cout << "YOU LOSE :(\n";
			break;
		}
	}
}
void CN4::twoPlayer() {
	while (true) {

		pair<int, int> lastPlay = CN4::userTurn(1);

		CN4::printBoard();
		if (CN4::gameOver(lastPlay, 1)) {
			cout << "RED WINS!!\n";
			break;
		}

		lastPlay = CN4::userTurn(2);
		CN4::printBoard();
		if (CN4::gameOver(lastPlay, 2)) {
			cout << "YELLOW WINSS!!\n";
			break;
		}
	}
}

pair<int, int> CN4::computerTurn(int player, int level) {
	//check for any moves that grant immediate win
	for (int i = 0; i < BOARD_WIDTH; i++) {
		int row_drop = CN4::pieceFall(i);
		pair<int, int> potential_move = make_pair(row_drop, i);

		if (CN4::gameOver(potential_move, 2)) {
			CN4::place(potential_move, player);
			return potential_move;
		}
	}

	//check for any moves that block players immediate win
	for (int i = 0; i < BOARD_WIDTH; i++) {
		int row_drop = CN4::pieceFall(i);
		pair<int, int> potential_move = make_pair(row_drop, i);

		if (CN4::gameOver(potential_move, 1)) {
			CN4::place(potential_move, player);
			return potential_move;
		}
	}

	//random play
	pair<int, int> potential_move;
	do {
		int col = rand() % BOARD_WIDTH;
		potential_move = place(col, player);
	} while (potential_move.first == -1);
	return potential_move;
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

bool CN4::gameOver(pair<int, int> lastPlay, int player) {
	int a = lastPlay.first;
	int b = lastPlay.second;

	int i, j;

	//check for vertical(|)
	int vertical = 1;
	for (i = a + 1; board[i][b] == player && i <= 5; i++, vertical++);//Check down
	for (i = a - 1; board[i][b] == player && i >= 0; i--, vertical++);//Check up
	if (vertical >= 4)return true;
	
	//check for horizontal(-)
	int horizontal = 1;
	for (j = b - 1; board[a][j] == player && j >= 0; j--, horizontal++);//Check left
	for (j = b + 1; board[a][j] == player && j <= 6; j++, horizontal++);//Check right
	if (horizontal >= 4) return true;
	
	//check for diagonal 1 (\)
	int diagonal1 = 1;
	for (i = a - 1, j = b - 1; i >= 0 && j >= 0 && board[i][j] == player; diagonal1++, i--, j--);//up and left
	for (i = a + 1, j = b + 1; i <= 5 && j <= 6 && board[i][j] == player; diagonal1++, i++, j++);//down and right
	if (diagonal1 >= 4) return true;
	
	//check for diagonal 2(/)
	int diagonal2 = 1;
	for (i = a - 1, j = b + 1; i >= 0 && j <= 6 && board[i][j] == player; diagonal2++, i--, j++);//up and right
	for (i = a + 1, j = b - 1; i <= 5 && j >= 0 && board[i][j] == player; diagonal2++, i++, j--);//up and left
	if (diagonal2 >= 4) return true;
	
	return false;
}

void CN4::place(pair<int, int> location, int player) {
	board[location.first][location.second] = player;
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
int CN4::pieceFall(int col) {
	if (col >= 0 && col < BOARD_WIDTH)
	{
		if (board[0][col] == 0) {
			int i;
			for (i = 0; board[i][col] == 0; i++)
				if (i == 5) {
					return i;
				}
			i--;
			return i;

		}
		else {
			return -1;
		}

	}
	else {
		return -1;
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