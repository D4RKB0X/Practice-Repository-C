#include <iostream>
#include <string>
#include <vector>

struct Book {
    std::string title;
    std::string author;
    unsigned int year;
    bool isAvailable = true;
};

class Library {
    private: 
        std::vector<Book> vBooks;
    
    public:
        Library(size_t reserveSize) { vBooks.reserve(reserveSize); }
        
        void addBook(const Book& aB) {
            vBooks.emplace_back(aB);
            std::cout << "Book titled: " << aB.title << " added to the library.\n";
        }
        
        void borrowBook(Book& bB) {
            if(bB.isAvailable) {
                std::cout << "\nTrying to borrow " << bB.title << "...\n";
                std::cout << "You have successfully borrowed " << bB.title << '\n';
            }
            else {
                std::cout << "\nTrying to borrow " << bB.title << "...\n";
                std::cout << "Sorry, " << bB.title << " is currently not available.\n";
            }
        }
        
        void returnBook(Book& rB) {
            if(rB.isAvailable == false) {
                rB.isAvailable = true;
                std::cout << "\nReturning " << rB.title << "...\n";
                std::cout << "You have successfully returned " << rB.title << '\n';
            }
        }
        
        void listAvailableBooks() const {
            std::cout << "\nAvailable books in the library:\n";
            
            for(const auto& list: vBooks) {
                if(list.isAvailable) {
                    std::cout << " - " << list.title << " by " << list.author << "(" << list.year << ")\n";
                }
            }
        }
};

int main() {
    
    Book firstBook{"The Hobbit", "J.R.R. Tolkein", 1937};
    Book secondBook{"1984", "George Orwell", 1949};
    Book thirdBook{"Pride and Prejudice", "Jane Austen", 1813};
    
    Library bookCollection(3);
    
    bookCollection.addBook(firstBook);
    bookCollection.addBook(secondBook);
    bookCollection.addBook(thirdBook);
    
    bookCollection.borrowBook(secondBook);
    bookCollection.borrowBook(secondBook);
    
    bookCollection.returnBook(secondBook);
    bookCollection.listAvailableBooks();
    
    return 0;
}
