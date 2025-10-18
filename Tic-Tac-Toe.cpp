#include <iostream>
#include <vector>
#include <limits>
#include <string>

template <typename T>
T getInput(const std::string& prompt) {
    T value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid input. Try again.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return value;
    }
}

void displayBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "\n";
    for (size_t i = 0; i < board.size(); ++i) {
        for (size_t j = 0; j < board[i].size(); ++j) {
            std::cout << " " << board[i][j];
            if (j < board[i].size() - 1)
                std::cout << " |";
        }
        std::cout << "\n";
        if (i < board.size() - 1)
            std::cout << "---+---+---\n";
    }
    std::cout << "\n";
}

bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;
    }

    return (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
           (board[0][2] == player && board[1][1] == player && board[2][0] == player);
}

bool isFull(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board)
        for (char cell : row)
            if (cell == ' ')
                return false;
    return true;
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameOver = false;

    std::cout << "=== Tic Tac Toe ===\n";
    displayBoard(board);

    while (!gameOver) {
        int row = getInput<int>("Enter row (1-3): ") - 1;
        int col = getInput<int>("Enter column (1-3): ") - 1;

        if (row < 0 || row >= 3 || col < 0 || col >= 3) {
            std::cerr << "Out of range. Please try again.\n";
            continue;
        }

        if (board[row][col] != ' ') {
            std::cerr << "Cell already taken. Try another.\n";
            continue;
        }

        board[row][col] = currentPlayer;
        displayBoard(board);

        if (checkWin(board, currentPlayer)) {
            std::cout << "Player " << currentPlayer << " wins!\n";
            gameOver = true;
        } else if (isFull(board)) {
            std::cout << "It's a draw!\n";
            gameOver = true;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}
