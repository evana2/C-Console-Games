// Console Games.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ConnectFour.h"
#include "TicTacToe.h"
int main()
{
    std::cout << "Hello World!\n";

    while (true) {
        std::cout << "Select a game to play:" << endl;
        std::cout << "(1) Connect Four" << endl;
        std::cout << "(2) Tic Tac Toe" << endl;
        std::cout << "(3) Quit" << endl;
        std::cout << "Selection: ";
        int userChoice;
        cin >> userChoice;

        while (1)
        {
            if (cin.fail() || userChoice < 1 || userChoice > 3)
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input, please try again: ";
                cin >> userChoice;
            }
            else {
                break;
            }
        }

        switch (userChoice)
        {
        case 1:
            CN4::runConnectFour();
            break;
        case 2:
            TTT::runTTT();
            break;
        case 3:
            return 0;
        }

    }
}