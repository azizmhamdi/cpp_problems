#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message) {
    int Number = 0;
    do {
        cout << Message << endl;
        cin >> Number;
    } while (Number < 0);
    return Number;
}

int CountDigitFrequency(short DigitToCheck, int Number) {
    int FreqCount = 0, Remainder = 0;
    while (Number > 0) {
        Remainder = Number % 10;
        if (DigitToCheck == Remainder) {
            FreqCount++;
        }
        Number = Number / 10;
    }
    return FreqCount;
}
void  PrintAllDigitsFrequencey(int Number) {
    // Loop through all digits from 0 to 9
    for (short Digit = 0; Digit <= 9; Digit++) {
        int Frequency = CountDigitFrequency(Digit, Number);
        if (Frequency > 0) {
            cout << "Digit " << Digit << " Frequency is " << Frequency << " Time(s)." << endl;
        }
    }

}

int main() {
    int Number = ReadPositiveNumber("Please enter the main number?");
    
    PrintAllDigitsFrequencey( Number);

    return 0;
}

