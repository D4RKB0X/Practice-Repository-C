#include <iostream>
#include <string>
#include <vector>
#include <memory>

struct Student {
    std::string name;
    double grade = 0.0;

    Student(const std::string& n, double g) : name(n), grade(g) {}
};

class StudentManager {
    private:
        std::vector<Student> honorStudents;
    
    public:
        void evaluateHonorStudents(const std::vector<Student>& students) {
            honorStudents.clear();
    
            for(const auto& s : students) {
                if (s.grade >= 85 && s.grade <= 100) {
                    honorStudents.emplace_back(s);
                }
            }
    
            if(honorStudents.empty()) {
                std::cout << "\nNo honor students found.\n";
            } 
            else {
                std::cout << "\nHonor students have been recorded successfully!\n";
            }
        }  

    void displayHonorStudents() const {
        if (honorStudents.empty()) {
            std::cout << "\nThere are no honor students to display.\n";
            return;
        }

        std::cout << "\n===== HONOR STUDENTS =====\n";
        for (const auto& h : honorStudents) {
            std::cout << "Name: " << h.name << ", Grade: " << h.grade << '\n';
        }
    }
};

void printAllStudents(const std::vector<Student>& students) {
    std::cout << "\n===== ALL STUDENTS =====\n";
    for (const auto& s : students) {
        std::cout << "Name: " << s.name << ", Grade: " << s.grade << '\n';
    }
}

int main() {
    auto vStudents = std::make_unique<std::vector<Student>>();
    int numOfStudents = 0;

    std::cout << "Enter the number of students: ";
    std::cin >> numOfStudents;

    if (numOfStudents <= 0) {
        std::cerr << "Invalid number. Please try again.\n";
        return 1;
    }

    for (size_t i = 0; i < static_cast<size_t>(numOfStudents); i++) {
        std::string name;
        double grade = 0.0;

        std::cout << "\nEnter the name of student " << i + 1 << ": ";
        std::cin >> name;

        std::cout << "Enter the grade of " << name << ": ";
        std::cin >> grade;

        vStudents->emplace_back(name, grade);
    }

    printAllStudents(*vStudents);

    StudentManager manager;
    manager.evaluateHonorStudents(*vStudents);
    manager.displayHonorStudents();

    return 0;
}
