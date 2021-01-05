#include <iostream>
using namespace std;
// Name: Amit Joshi
//ASMT03 Part A

bool isWon(char, char[][3]);
bool isDraw(char[][3]);
void displayBoard(char[][3]);
void makeAMove(char[][3], char);
int main() {
    //
    // PLEASE DO NOT CHANGE function main
    //
    char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
    displayBoard(board);

    while (true) {
  // The first player makes a move
        makeAMove(board, 'X');
        displayBoard(board);
        if (isWon('X', board)) {
            cout << "X player won" << endl;
            exit(0);
        }
        else if (isDraw(board)) {
            cout << "No winner" << endl;
            exit(0);
        }

        // The second player makes a move
        makeAMove(board, 'O');
        displayBoard(board);

        if (isWon('O', board)) {
            cout << "O player won" << endl;
            exit(0);
        }
        else if (isDraw(board)) {
            cout << "No winner" << endl;
            exit(0);
        }
    }

    return 0;
}

bool isWon(char x, char board[][3]) {

    if (board[0][0] == x && board[1][1] == x && board[2][2] == x)
        return true;
    if (board[0][2] == x && board[1][1] == x && board[2][0] == x)
        return true;

    for (int i = 0; i < 3; i++) {
        if (board[0][i] == x && board[1][i] == x && board[2][i] == x)
            return true;
        if (board[i][0] == x && board[i][1] == x && board[i][2] == x)
            return true;
    }
    return false;
}

bool isDraw(char board[][3]) {
    //Set Counter = 0 and start a for loop
    int counter = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X' || board[i][j] == 'O')
                counter++;
        }
    }
    if (counter < 9)
        return false;
    else if (isWon('X', board) == false && isWon('O', board) == false)
        return true;
    return false;
}
void displayBoard(char board[][3]) {

    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "|  " << board[i][j];
        }
        //draw the display
        cout << "|" << endl;
        cout << "_____________\n";
    }
}

void makeAMove(char board[][3], char x) {
    do {
        int rows = 'null';
        cout << "Enter a row (0,1,2) for player " << x << " : ";
        cin >> rows;

        int column = 'null';
        cout << "Enter a column (0,1,2) for player " << x << " : ";
        cin >> column;

        if (rows < 0 || column > 2 || rows < 0 || column > 2) {
            cout << "Invalid Move\n";
        }
        else {
            if (board[rows][column] != 'X' && board[rows][column] != 'O') {
                board[rows][column] = x;
                break;
            }
            else {
                cout << "This cell is already occupied.Try a dufferent cell\n";
            }
        }
    } while (true);
}
