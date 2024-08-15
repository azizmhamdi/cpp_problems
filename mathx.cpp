#include <iostream>
#include <string>

using namespace std;

// Function to read a positive number from the user
int ReadPositiveNumber(string Message) {
    int Number = 0;
    do {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

// Function to calculate the sum of digits of a number
int SumOfDigits(int Number) {
    int Sum = 0, Remainder = 0;
    while (Number > 0) {
        Remainder = Number % 10;
        Number = Number / 10;
        Sum += Remainder;
    }
    return Sum;
}

int main() {
    int Number = ReadPositiveNumber("Please enter a positive number?");
    int Sum = SumOfDigits(Number);
    cout << "\nSum Of Digits = " << Sum << "\n";
    return 0;
}
