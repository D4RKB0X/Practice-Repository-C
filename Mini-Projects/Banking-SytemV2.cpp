#include <iostream>
#include <vector>
#include <string>


class BankAccount {
  private:
      unsigned int accountNumber;
      std::string ownerName;
      float balance;

  public:
      BankAccount(unsigned int accNum, const std::string& name, float initialBalance = 0.0f)
          : accountNumber(accNum), ownerName(name), balance(initialBalance) {}
  
      float getBalance() const { return balance; }
      unsigned int getAccountNumber() const { return accountNumber; }
      std::string getOwnerName() const { return ownerName; }

      void deposit(float amount) {
          if (amount <= 0) {
              std::cout << "Deposit must be positive.\n";
              return;
          }
        
          balance += amount;
          std::cout << "Deposited " << amount << ". New balance: " << balance << "\n";
      }
  
      void withdraw(float amount) {
          if (amount <= 0) {
              std::cout << "Withdrawal must be positive.\n";
              return;
          }
        
          if (amount > balance) {
              std::cout << "Insufficient funds.\n";
              return;
          }
        
          balance -= amount;
          std::cout << "Withdrawn " << amount << ". New balance: " << balance << "\n";
      }
  
      void displayInfo() const {
          std::cout << "Account #" << accountNumber
                    << " | Owner: " << ownerName
                    << " | Balance: " << balance << "\n";
      }
};

class Menu {
  private:
      std::vector<BankAccount> accounts;
  
      BankAccount* selectAccount() {
          if (accounts.empty()) {
              std::cout << "No accounts available.\n";
              return nullptr;
          }
  
          std::cout << "\nAvailable accounts:\n";
          for (size_t i = 0; i < accounts.size(); i++) {
              std::cout << "[" << i << "] Account #" << accounts[i].getAccountNumber()
                        << " | Owner: " << accounts[i].getOwnerName() << "\n";
          }
  
          size_t choice;
          std::cout << "Select account by number: ";
          std::cin >> choice;
        
          if (choice >= accounts.size()) {
              std::cout << "Invalid selection.\n";
              return nullptr;
          }
          return &accounts[choice];
      }

  public:
      void addAccount(const BankAccount& account) {
          accounts.push_back(account);
      }
  
      void start() {
          unsigned int mainChoice;
          do {
              std::cout << "\n=== Banking System Menu ===\n"
                        << "1. Create Account\n"
                        << "2. Select Account\n"
                        << "3. Exit\n"
                        << "Enter choice: ";
              std::cin >> mainChoice;
  
              switch (mainChoice) {
                  case 1: {
                      unsigned int accNum;
                      std::string name;
                      float initialBalance;
                    
                      std::cout << "Enter account number: ";
                      std::cin >> accNum;
                      std::cin.ignore();
                    
                      std::cout << "Enter owner name: ";
                      std::getline(std::cin, name);
                    
                      std::cout << "Enter initial balance: ";
                      std::cin >> initialBalance;
  
                      accounts.emplace_back(accNum, name, initialBalance);
                      std::cout << "Account created successfully!\n";
                      break;
                  }
                  case 2: {
                      BankAccount* account = selectAccount();
                      if (account) {
                          unsigned int action;
                          do {
                              std::cout << "\n--- Account Menu ---\n"
                                        << "1. Deposit\n"
                                        << "2. Withdraw\n"
                                        << "3. Display Info\n"
                                        << "4. Back to Main Menu\n"
                                        << "Enter choice: ";
                              std::cin >> action;
  
                              switch (action) {
                                  case 1: {
                                      float amt;
                                      std::cout << "Enter amount to deposit: ";
                                      std::cin >> amt;
                                      account->deposit(amt);
                                      break;
                                  }
                                  case 2: {
                                      float amt;
                                      std::cout << "Enter amount to withdraw: ";
                                      std::cin >> amt;
                                      account->withdraw(amt);
                                      break;
                                  }
                                  case 3:
                                      account->displayInfo();
                                      break;
                                  case 4:
                                      std::cout << "Returning to main menu...\n";
                                      break;
                                  default:
                                      std::cout << "Invalid option.\n";
                                      break;
                              }
                          } while (action != 4);
                      }
                      break;
                  }
                  case 3:
                      std::cout << "Exiting system. Goodbye!\n";
                      break;
                  default:
                      std::cout << "Invalid option.\n";
                      break;
              }
          } while (mainChoice != 3);
      }
};

int main() {
    Menu menu;
    menu.start();
    return 0;
}
