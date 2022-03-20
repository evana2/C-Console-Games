#pragma once

#include <iostream>
#include <utility>
#include <Windows.h>

using namespace std;

namespace CN4  // namespace declaration
{
	#define COLOR_SQUARE 0xDB
	#define BLACK_SQUARE 0xFF
	#define BOARD_WIDTH 7
	#define BOARD_HEIGHT 6

	//set color of console
	void setRed();
	void setYellow();
	void setWhite();

	//print full board with all pieces
	void printBoard();
	//helper function to printBoard
	void printLine(int row);

	//place a piece for given player in selected column
	pair<int, int> place(int col, int player);
	//checks if a specific play has caused a four in a row, ending the game
	bool gameOver(pair<int, int> lastPlay);
	//prompt the user to play, returns the successful move as a pair of board coordinates
	pair<int, int> userTurn(int player);

	//main function, runs game
	void runConnectFour();
}