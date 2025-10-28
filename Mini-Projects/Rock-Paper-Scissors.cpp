#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

std::string choiceToWord(int choice) {
    switch (choice) {
        case 1: return "Rock";
        case 2: return "Paper";
        case 3: return "Scissors";
        default: return "Unknown";
    }
}

int getInput() {
    int choice;
    while (true) {
        std::cout << "\nChoose:\n"
                  << "[1] - Rock\n"
                  << "[2] - Paper\n"
                  << "[3] - Scissors\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail() || choice < 1 || choice > 3) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input, try again.\n";
        }
        else {
            return choice;
        }
    }
}

void playRound(int player, int computer) {
    std::cout << "You chose: " << choiceToWord(player)
              << " | Computer chose: " << choiceToWord(computer) << "\n";

    if (player == computer) {
        std::cout << "Stalemate!\n";
    } 
    else if ((player == 1 && computer == 3) ||
             (player == 2 && computer == 1) ||
             (player == 3 && computer == 2)) {
        std::cout << "You Win!\n";
    }
    else {
        std::cout << "You Lose!\n";
    }
}

int main() {
    srand(static_cast<unsigned>(time(NULL)));
    std::cout << "Welcome to Rock-Paper-Scissors!\n";

    char again;
    do {
        int player = getInput();
        int computer = rand() % 3 + 1;
        playRound(player, computer);

        std::cout << "\nPlay again? (Y/N): ";
        std::cin >> again;
    } while (again == 'Y' || again == 'y');

    std::cout << "\nThanks for playing!";
    return 0;
}
