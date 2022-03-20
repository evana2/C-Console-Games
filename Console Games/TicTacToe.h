#pragma once
#include <iostream>
#include <Windows.h>

namespace TTT  // namespace declaration
{
	#define W_SQR char(0xDB)
	#define B_SQR char(0xFF)

	void runTTT();

	//display board to console
	void printBoard(char board[3][3]);

	//check game status
	// 0 -> in progress
	// 1 -> X wins
	// 2 -> O wins
	int gameStatus(char board[3][3]);
}