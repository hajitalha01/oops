#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[9]; // Tic-Tac-Toe board
    char currentPlayer; // Current player's symbol (X or O)

public:
    // Constructor to initialize the board
    TicTacToe() {
        for (int i = 0; i < 9; i++)
            board[i] = ' ';
        currentPlayer = 'X'; // First player starts with 'X'
    }

    // Function to display the board
    void displayBoard() {
        cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
        cout << "---+---+---" << endl;
        cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
        cout << "---+---+---" << endl;
        cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
    }

    // Function to make a move
    bool makeMove(int position) {
        if (position < 0 || position >= 9 || board[position] != ' ') {
            cout << "Invalid move! Try again.\n";
            return false;
        }
        board[position] = currentPlayer;
        return true;
    }

    // Function to check if the game is won
    bool isWin() {
        int winPatterns[8][3] = {
            {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
            {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
            {0, 4, 8}, {2, 4, 6}  // Diagonals
        };

        for (auto &pattern : winPatterns) {
            if (board[pattern[0]] == currentPlayer &&
                board[pattern[1]] == currentPlayer &&
                board[pattern[2]] == currentPlayer) {
                return true;
            }
        }
        return false;
    }

    // Function to check if the board is full (Draw)
    bool isDraw() {
        for (char c : board) {
            if (c == ' ') return false;
        }
        return true;
    }

    // Function to switch players
    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Function to start the game
    void play() {
        int position;
        while (true) {
            displayBoard();
            cout << "Player " << currentPlayer << ", enter position (0-8): ";
            cin >> position;

            if (!makeMove(position)) continue;

            if (isWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }
            if (isDraw()) {
                displayBoard();
                cout << "It's a draw!\n";
                break;
            }

            switchPlayer();
        }
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}

