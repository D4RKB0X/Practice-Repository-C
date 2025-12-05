#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    int assignmentScore = 0;
    int examScore = 0;

    double finalGrade() const {
        return (assignmentScore + examScore) / 2.0;
    }

    void printResult() const {
        std::cout << name << "'s final grade: " << finalGrade() << "\n";
    }
};

int main() {
    std::vector<Student> students;
    int numStudents;

    std::cout << "How many students? ";
    std::cin >> numStudents;
    std::cin.ignore();

    for (int i = 0; i < numStudents; ++i) {
        std::string name;
        int assignmentScore, examScore;

        std::cout << "\nEnter name for student #" << (i + 1) << ": ";
        std::getline(std::cin, name);

        std::cout << "Enter assignment score: ";
        std::cin >> assignmentScore;

        std::cout << "Enter exam score: ";
        std::cin >> examScore;
        std::cin.ignore();
      
        students.emplace_back(Student{name, assignmentScore, examScore});
    }

    std::cout << "\n=== Final Grades ===\n";
    for (const auto& s : students) {
        s.printResult();
    }

    return 0;
}
