#include <iostream>

using namespace std;
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';


void displayBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}


bool checkWin(char board[3][3], char player) {
    
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}


bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;  
        }
    }
    return true;  
}

int main() {
    char board[3][3]{};  
    char currentPlayer = PLAYER_X;  
    bool gameWon = false;
    bool gameDraw = false;

    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }

    do {
        
        displayBoard(board);

        
        cout << "Player " << currentPlayer << ", enter your move (row [0-2] and column [0-2] separated by a space): ";
        int row, col;
        cin >> row >> col;

        
        if (board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            gameWon = checkWin(board, currentPlayer);
            gameDraw = checkDraw(board);

            
            currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
        }
        else {
            cout << "Cell already taken. Try again.\n";
        }

    } while (!gameWon && !gameDraw);

    
    displayBoard(board);

    
    if (gameWon) {
        cout << "Player " << ((currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X) << " wins!\n";
    }
    else {
        cout << "It's a draw!\n";
    }

    
    char playAgain;
    cout << "Play again? (y/n): ";
    cin >> playAgain;
    if (playAgain == 'y' || playAgain == 'Y') {
        main();  
    }

    return 0;
}
