#include <iostream>

class Door {
    private:
        bool isLocked;
        
    public:
        Door(): isLocked(false) {}
        
        void lockDoor() {
            isLocked = true;
        }
        
        void unlockDoor() {
            isLocked = false;
        } 
        
        bool getStatus() const { return isLocked; }
        void printStatus() const {
            if(getStatus()) {
                std::cout << "Door is Locked!\n";
            }
            else {
                std::cout << "Door is Unlocked!\n";
            }
        }
};

class Menu {
    public:
        void startMenu(Door& door) {
            unsigned int mainChoice;
            
            do {
                std::cout << "1. Lock Door\n"
                          << "2. Unlock Door\n"
                          << "3. Check Status\n"
                          << "4. Exit\n"
                          << "Enter your choice: ";
                std::cin >> mainChoice;
                
                switch (mainChoice) {
                    case 1: {
                        door.lockDoor();
                        std::cout << "\nDoor is now locked!\n";
                        break;
                    }
                    
                    case 2: {
                        door.unlockDoor();
                        std::cout << "\nDoor is now unlocked!\n";
                        break;
                    }
                    
                    case 3: {
                        std::cout << "\nDoor status: ";
                        door.printStatus(); 
                        break;
                    }
                    
                    case 4: {
                        break;
                    }
                }
                std::cout << '\n';
            } while (mainChoice != 4);
        }
};

int main() {
    
    Door frontDoor;
    Menu menu;
    menu.startMenu(frontDoor);
    
    return 0;
}
