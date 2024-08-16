 
#include <iostream>

using namespace std;

int ReadPositiveNumber(string Message) {
    int Number = 0;
    do {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}


void printInverted(int number) {
    for (int i = 1; i <= number; i++) {
        for (int j = 1; j <= i; j++) {
            cout <<i ;   
        }
        cout << endl;
    }
}

int main() {
    int number = ReadPositiveNumber("Enter a positive number:"); // Read the number and store it
    printInverted(number); // Print the inverted pattern
    return 0;
}
