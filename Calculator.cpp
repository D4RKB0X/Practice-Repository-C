#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

void printNumbers() {
    int n;
    cout << "Enter a Number to Loop: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << i << endl;
    }
}

void naturalNumbers() {
    int n, sum = 0;
    cout << "Enter the Value of N: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    cout << "Sum of the Value is: " << sum << endl;
}

void factorialNumbers() {
    int n, fact = 1;
    cout << "Enter a Number: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    cout << "Factorial of the Number is: " << fact << endl;
}

void multiplicationTable() {
    int n;
    cout << "Enter a Number: ";
    cin >> n;

    for (int i = 1; i <= 10; i++) {
        cout << i << " x " << n << " = " << i * n << endl;
    }
}

void printPattern() {
    int n;
    cout << "Enter a Number: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

static bool isPrime(int n) {
    if (n <= 1) return false;

    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void primeNumber() {
    int a;
    cout << "Enter a Number: ";
    cin >> a;

    if (isPrime(a)) {
        cout << a << " is a Prime Number" << endl;
    } else {
        cout << a << " is not a Prime Number" << endl;
    }
}

void reverseNumbers() {
    int n, rn = 0, r;
    cout << "Enter a Number: ";
    cin >> n;

    while (n != 0) {
        r = n % 10;
        rn = rn * 10 + r;
        n /= 10;
    }

    cout << "Reversed Number: " << rn << endl;
}

void SumOfOddandEven() {
    int n, oddSum = 0, evenSum = 0;
    cout << "Enter a Number: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            evenSum += i;
        } else {
            oddSum += i;
        }
    }

    cout << "Sum of Odd is: " << oddSum << endl;
    cout << "Sum of Even is: " << evenSum << endl;
}

int main() {
    int choose;
    char repeat;

    while (true) {
        cout << "---------------------------------------------" << endl;
        cout << "Choose a Function to use:" << endl;
        cout << "[1] - Print Numbers" << endl;
        cout << "[2] - Sum of Natural Numbers" << endl;
        cout << "[3] - Factorial of a Number" << endl;
        cout << "[4] - Multiplication Table" << endl;
        cout << "[5] - Print a Pattern" << endl;
        cout << "[6] - Check Prime Number" << endl;
        cout << "[7] - Reverse a Number" << endl;
        cout << "[8] - Sum of Odd and Even Numbers" << endl;

        cout << "\nEnter a Number: ";
        cin >> choose;

        switch (choose) {
            case 1: cout << "\nPrint Numbers Function\n"; printNumbers(); break;
            case 2: cout << "\nSum of Natural Numbers Function\n"; naturalNumbers(); break;
            case 3: cout << "\nFactorial of a Number Function\n"; factorialNumbers(); break;
            case 4: cout << "\nMultiplication Table Function\n"; multiplicationTable(); break;
            case 5: cout << "\nPrint a Pattern Function\n"; printPattern(); break;
            case 6: cout << "\nCheck Prime Number Function\n"; primeNumber(); break;
            case 7: cout << "\nReverse Number Function\n"; reverseNumbers(); break;
            case 8: cout << "\nSum of Odd and Even Numbers Function\n"; SumOfOddandEven(); break;
            default: cout << "Error! Please Reset and Try Again.\n"; break;
        }

        cout << "\nWould You Like to Try Again (Y/N): ";
        cin >> repeat;

        if (repeat == 'n' || repeat == 'N') {
            cout << "Exiting Program" << endl;
            break;
        }
        cout << "\n";
    }

    return 0;
}
