#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <limits>

struct Question {
    std::string questionText;
    std::vector<std::string> options;
    char correctAnswer;
};

char getInput(const std::string& prompt) {
    char value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        value = toupper(value);

        if (std::cin.fail() || !(value == 'A' || value == 'B' || value == 'C' || value == 'D')) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "\nInvalid input, please enter A, B, C, or D.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

void displayQuestion(const Question& quiz) {
    std::cout << quiz.questionText << '\n';
    for (const auto& option : quiz.options) {
        std::cout << option << '\n';
    }
}

int playQuiz(std::vector<Question>& quizQuestions) {
    int score = 0;

    for (auto& ask : quizQuestions) {
        displayQuestion(ask);
        char userAnswer = getInput("Enter your answer (A|B|C|D): ");
        if (userAnswer == ask.correctAnswer) {
            std::cout << "\nCorrect!\n\n";
            score++;
        } else {
            std::cout << "\nWrong! The correct answer was " << ask.correctAnswer << "\n\n";
        }
    }

    return score;
}

int main() {
    
    std::vector<Question> quizQuestions = {
        {"What is the capital of France?",
        {"A. Berlin", "B. Paris", "C. Rome", "D. Madrid"}, 'B'},

        {"Which planet is known as the Red Planet?",
        {"A. Earth", "B. Mars", "C. Jupiter", "D. Venus"}, 'B'},

        {"Which language is used for system programming?",
        {"A. C++", "B. Python", "C. HTML", "D. JavaScript"}, 'A'},

        {"How many continents are there on Earth?",
        {"A. 5", "B. 6", "C. 7", "D. 8"}, 'C'},

        {"Which element has the chemical symbol 'O'?",
        {"A. Oxygen", "B. Gold", "C. Iron", "D. Hydrogen"}, 'A'}
    };

    int score = playQuiz(quizQuestions);
    std::cout << "Your final score: " << score << "/" << quizQuestions.size() << "\n";

    return 0;
}
