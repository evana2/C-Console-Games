#include "TicTacToe.h"
using namespace TTT;
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//three lines making up the X character
#define XL1 W_SQR << W_SQR << B_SQR << B_SQR << W_SQR << W_SQR
#define XL2 B_SQR << B_SQR << W_SQR << W_SQR << B_SQR << B_SQR
#define XL3 W_SQR << W_SQR << B_SQR << B_SQR << W_SQR << W_SQR

//three lines maxing up the O character
#define OL1 B_SQR << B_SQR << W_SQR << W_SQR << B_SQR << B_SQR
#define OL2 W_SQR << W_SQR << B_SQR << B_SQR << W_SQR << W_SQR
#define OL3 B_SQR << B_SQR << W_SQR << W_SQR << B_SQR << B_SQR

//blank square
#define EMPTY B_SQR << B_SQR << B_SQR << B_SQR << B_SQR << B_SQR

//dividing lines
void printMiddleLine() {
    SetConsoleTextAttribute(hConsole, 9); 
    for (int i = 0; i < 24; i++) { 
        cout << W_SQR; 
    } 
    cout << endl; 
    SetConsoleTextAttribute(hConsole, 7);
}
void printTopLine() {
    SetConsoleTextAttribute(hConsole, 9);
    cout << B_SQR;
    for (int r = 0; r < 2; r++) {
        for (int i = 0; i < 6; i++) {
            cout << B_SQR;
        }
        cout << W_SQR << W_SQR;
    }
    cout << endl;
    SetConsoleTextAttribute(hConsole, 7);
}


void TTT::runTTT() {
    char board[3][3] = { {' ', 'X', ' '}, { 'O', ' ', ' ' }, { 'X', ' ', ' ' } };
    printBoard(board);
}

void TTT::printBoard(char board[3][3]) {
    printTopLine();
    for (int i = 0; i < 3; i++) {
        for (int r = 0; r < 3; r++) {
            cout << B_SQR;
            for (int j = 0; j < 3; j++) {
                switch (board[i][j]) {
                case ' ':
                    cout << EMPTY;
                    break;
                case 'X':
                    if (r == 0) { cout << XL1; }
                    if (r == 1) { cout << XL2; }
                    if (r == 2) { cout << XL3; }
                    break;
                case 'O':
                    if (r == 0) { cout << OL1; }
                    if (r == 1) { cout << OL2; }
                    if (r == 2) { cout << OL3; }
                    break;
                }
                if (j != 2) {
                    SetConsoleTextAttribute(hConsole, 9);
                    cout << W_SQR << W_SQR;
                    SetConsoleTextAttribute(hConsole, 7);
                }
            }
            cout << endl;
        }
        if (i != 2) {
            printMiddleLine();
        }
    }
    printTopLine();
}

int TTT::gameStatus(char board[3][3]) {
    return 0;
}