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

    char board[3][3] = { {' ', ' ', ' '}, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    printBoard(board);

    while (!gameStatus(board)) {
        //player turn 
        int x;
        int y;
        std::cin >> x;
        std::cin >> y;
        board[x][y] = 'X';
        printBoard(board);

        //computer turn
        std::cin >> x;
        std::cin >> y;
        board[x][y] = 'O';
        printBoard(board);
    }
    int winner = gameStatus(board);
    if (winner == 1) {
        std::cout << "X WINS!!";
    }
    else {
        std::cout << "O WINS!!";
    }
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
    //check rows
    for (int i = 0; i < 3; i++) {
        char rowVal = board[i][0];
        bool flag = true;
        for (int j = 1; j < 3; j++) {
            if (rowVal != board[i][j]) {
                flag = false;
                break;
            }
        }
        if (rowVal != ' ' && flag) {
            if (rowVal == 'X') {
                return 1;
            }
            else {
                return 2;
            }
        }
    }
    //check columns
    for (int j = 0; j < 3; j++) {
        char rowVal = board[0][j];
        bool flag = true;
        for (int i = 1; i < 3; i++) {
            if (rowVal != board[i][j]) {
                flag = false;
                break;
            }
        }
        if (rowVal != ' ' && flag) {
            if (rowVal == 'X') {
                return 1;
            }
            else {
                return 2;
            }
        }
    }
    //check diagonals
    char diVal1 = board[0][0];
    char diVal2 = board[2][0];
    bool flag1 = true;
    bool flag2 = true;
    for (int i = 1; i < 3; i++) {
        if (flag1 && diVal1 != board[i][i]) {
            flag1 = false;
        }
        if (flag2 && diVal2 != board[2 - i][i]) {
            flag2 = false;
        }
    }
    if (diVal1 != ' ' && flag1) {
        if (diVal1 == 'X') {
            return 1;
        }
        else {
            return 2;
        }
    }
    if (diVal2 != ' ' && flag2) {
        if (diVal2 == 'X') {
            return 1;
        }
        else {
            return 2;
        }
    }

    return 0;
}