#pragma once

#include <iostream>
#include <utility>
#include <Windows.h>
#include <stdlib.h> //rand()

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

	//remove all pieces from board
	void clearBoard();

	//place a piece for given player in selected column
	pair<int, int> place(int col, int player);
	void place(pair<int, int> location, int player);
	
	//gives the int of the row a piece will fall to if placed
	int pieceFall(int col);

	//checks if a specific play has caused a four in a row, ending the game
	bool gameOver(pair<int, int> lastPlay, int player);
	//prompt the user to play, returns the successful move as a pair of board coordinates
	pair<int, int> userTurn(int player);


	//AI for play against computer
	pair<int, int> computerTurn(int player, int level);
	
	//main function, runs game
	void runConnectFour();
	void onePlayer();
	void twoPlayer();
}