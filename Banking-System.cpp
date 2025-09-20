#include <iostream>
#include <string>
#include <limits>

template <typename T>
T getInput(const std::string& prompt) {
    T value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nInvalid input, try again.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return value;
    }
}

bool confirm(const std::string& action) {
    char proceed;
    std::cout << "\nDo you want to proceed with " << action << "? (Y/N): ";
    std::cin >> proceed;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    return (proceed == 'Y' || proceed == 'y');
}

void deposit(int &balance, int &counter_deposit) {
    int cash = getInput<int>("How much do you want to deposit?: ");
    if (cash <= 0) {
        std::cout << "\nAmount must be positive!\n";
        return;
    }
    balance += cash;
    counter_deposit++;
    std::cout << "\nDeposit successful! Your new balance is: " << balance << "\n";
}

void withdraw(int &balance, int &counter_withdraw) {
    int cash = getInput<int>("How much do you want to withdraw?: ");
    if (cash <= 0) {
        std::cout << "\nAmount must be positive!\n";
        return;
    }
    if (cash > balance) {
        std::cout << "\nInsufficient funds!\n";
        return;
    }
    balance -= cash;
    counter_withdraw++;
    std::cout << "\nWithdrawal successful! Your new balance is: " << balance << "\n";
}

void menu(int &balance, std::string &fullname) {
    int counter_deposit = 0, counter_withdraw = 0;
    char again;

    do {
        int choose = getInput<int>(
            "\nSelect an action:\n"
            "[1] - Deposit\n"
            "[2] - Withdraw\n"
            "[3] - Check Balance\n"
            "[4] - View Account\n"
            "\nEnter the number here: "
        );

        switch (choose) {
            case 1:
                if (confirm("Deposit")) deposit(balance, counter_deposit);
                else std::cout << "Cancelled\n";
                break;

            case 2:
                if (confirm("Withdraw")) withdraw(balance, counter_withdraw);
                else std::cout << "Cancelled\n";
                break;

            case 3:
                if (confirm("Check Balance"))
                    std::cout << "\nYour current balance is: " << balance << "\n";
                else std::cout << "Cancelled\n";
                break;

            case 4:
                if (confirm("View Account")) {
                    std::cout << "\nHello, " << fullname << "!\n";
                    std::cout << "Current balance: " << balance << "\n";
                    std::cout << "Deposited " << counter_deposit << " times.\n";
                    std::cout << "Withdrawn " << counter_withdraw << " times.\n";
                }
                else std::cout << "Cancelled\n";
                break;

            default:
                std::cout << "\nInvalid option, try again!\n";
                break;
        }

        std::cout << "\nDo you want to perform another action? (Y/N): ";
        std::cin >> again;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (again == 'Y' || again == 'y');

    std::cout << "\nGoodbye!\n";
}

int main() {
    int balance = 0;
    std::string fullname;

    std::cout << "Welcome to the banking system!\n";
    std::cout << "Enter your name: ";
    std::getline(std::cin, fullname);

    menu(balance, fullname);

    return 0;
}
