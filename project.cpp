#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Sudoku {
private:
    static const int N = 9;
    char board[N][N];

public:
	// initialize board
    Sudoku() {
        srand(time(0));

        
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                board[i][j] = '*';
    }

    //  is it safe
    bool isSafe(int row, int col, char num) {
	//R&C 
        for (int x = 0; x < N; x++) {

            if (board[row][x] == num || board[x][col] == num)
                return false;
        }

        // 3x3 check
        int startRow = row - row % 3;
        int startCol = col - col % 3;

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[startRow + i][startCol + j] == num)
                    return false;

        return true;
    }

    // Solver
    bool solveSudoku() {

        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {

                if (board[row][col] == '*') {

                    for (char num = '1'; num <= '9'; num++) {

                        if (isSafe(row, col, num)) {

                            board[row][col] = num;

                            if (solveSudoku()) //backtrack
                                return true;

                            board[row][col] = '*';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    // Print board
    void printBoard() {

        for (int i = 0; i < N; i++) {

            for (int j = 0; j < N; j++){
            
                cout << board[i][j] << " ";
		}
            cout << endl;
        }
    }

    // Fill 3x3 box
    void fillBox(int row, int col) {

        char num;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {

                do {
                    num = (rand() % 9) + '1';
                }
                while (!isSafe(row + i, col + j, num));

                board[row + i][col + j] = num;
            }
        }
    }

    // Fill diagonal boxes
    void fillDiagonal() {

        for (int i = 0; i < N; i += 3)
            fillBox(i, i);
    }

    // Remove digits
    void removeDigits(int count) {

        while (count > 0) {

            int i = rand() % 9;
            int j = rand() % 9;

            if (board[i][j] != '*') {

                board[i][j] = '*';
                count--;
            }
        }
    }

    // Generate Sudoku
    void generateSudoku() {

        fillDiagonal();
        solveSudoku();
        removeDigits(40);
    }
};

int main() {

    Sudoku game;

    // Generate
    game.generateSudoku();

    cout << "Generated Sudoku:\n";
    game.printBoard();

    // Solve
    if (game.solveSudoku()) {

        cout << "\nSolved Sudoku:\n";
        game.printBoard();
    }
    else {
        cout << "No solution exists\n";
    }

    return 0;
}