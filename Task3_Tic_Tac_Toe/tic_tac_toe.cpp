#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer = 'X';

// Initialize the game board
void initializeBoard() {
    char value = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = value++;
        }
    }
}

// Display the board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
        if (i < 2)
            cout << "---|---|---" << endl;
    }
    cout << endl;
}

// Check if a player has won
bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer)
            return true;

        if (board[0][i] == currentPlayer &&
            board[1][i] == currentPlayer &&
            board[2][i] == currentPlayer)
            return true;
    }

    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer)
        return true;

    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer)
        return true;

    return false;
}

// Check if the game is a draw
bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;

    return true;
}

int main() {
    initializeBoard();

    int choice;

    while (true) {
        displayBoard();

        cout << "Player " << currentPlayer << ", enter position (1-9): ";
        cin >> choice;

        bool moveMade = false;

        for (int i = 0; i < 3 && !moveMade; i++) {
            for (int j = 0; j < 3 && !moveMade; j++) {
                if (board[i][j] == choice + '0') {
                    board[i][j] = currentPlayer;
                    moveMade = true;
                }
            }
        }

        if (!moveMade) {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        if (checkWin()) {
            displayBoard();
            cout << "🎉 Player " << currentPlayer << " Wins!\n";
            break;
        }

        if (checkDraw()) {
            displayBoard();
            cout << "Game Draw!\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}