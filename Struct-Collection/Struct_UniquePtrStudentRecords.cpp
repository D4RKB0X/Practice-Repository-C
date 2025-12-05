#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
#include <limits>

struct Student{
    std::string name;
    int age = 0;
    double grade = 0.0;
    
    Student() = default;
    Student(const std::string& n, int a, double g) {
        name = n;
        age = a;
        grade = g;
    }
};

void printStudents(const std::unique_ptr<std::vector<Student>>& vStudents) {
    for(const auto& list: *vStudents) {
        std::cout << "\n----------\n";
        std::cout << "Name: " << list.name << '\n';
        std::cout << "Age: " << list.age << '\n';
        std::cout << "Grade: " << list.grade << '\n';
    }
}

void findStudent(const std::unique_ptr<std::vector<Student>>& vStudent) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string findName;
    
    std::cout << "\nEnter the student you want to find: ";
    std::getline(std::cin, findName);
    
    auto it = std::find_if(vStudent->begin(), vStudent->end(), [&](const Student& s) {
        return s.name == findName;
    });

    if (it != vStudent->end()) {
        std::cout << findName << " is found!\n";
        std::cout << "Age: " << it->age << "\n";
        std::cout << "Grade: " << it->grade << "\n";
    }
    else {
        std::cout << findName << " is not found!\n";
    }

}

int main() {
    auto vStudents = std::make_unique<std::vector<Student>>();
    int numStudents = 0;
    
    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;
    
    if(numStudents <= 0) {
        return 1;
    }
    
    vStudents->reserve(numStudents);
    
    for(size_t i = 0; i < numStudents; i++) {
        std::string name;
        int age = 0;
        double grade = 0.0;
        
        std::cout << "\nEnter the name of student " << i + 1 << ": ";
        std::cin >> value.name;
        
        std::cout << "Enter the age of " << value.name << ": ";
        std::cin >> value.age;
        
        std::cout << "Enter the grade of " << value.name << ": ";
        std::cin >> value.grade;
        
        vStudents->emplace_back(name, age, grade);
    }
    
    printStudents(vStudents);
    findStudent(vStudents);
    
    return 0;
}
