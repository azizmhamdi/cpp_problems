#include <iostream>
#include <string>
#include <cmath>   

using namespace std;

enum enPrimNotPrime {
    Prime = 1,
    NotPrime = 2
};

int ReadPositiveNumber(string Message) {
    int Number = 0;
    do {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

enPrimNotPrime CheckPrime(int Number) {
    if (Number < 2) {
        return enPrimNotPrime::NotPrime;  
    }
    int M = round(Number / 2.0);   
    for (int Counter = 2; Counter <= M; Counter++) {
        if (Number % Counter == 0) {
            return enPrimNotPrime::NotPrime;
        }
    }
    return enPrimNotPrime::Prime;
}

void PrintPrimeNumbersFrom1ToN(int Number) {
    cout << "\n";
    cout << "Prime Numbers from " << 1 << " to " << Number << " are:" << endl;
    for (int i = 1; i <= Number; i++) {
        if (CheckPrime(i) == enPrimNotPrime::Prime) {
            cout << i << endl;
        }
    }
}

int main() {
    int Number = ReadPositiveNumber("Please enter a positive number:");
    PrintPrimeNumbersFrom1ToN(Number);
    return 0;
}
