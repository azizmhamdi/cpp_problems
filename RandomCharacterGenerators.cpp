


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

 
enum CharType {
    SmallLetter,
    CapitalLetter,
    SpecialCharacter,
    Digit
};

 
int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

 
char GenerateRandomChar(CharType type) {
    switch (type) {
    case SmallLetter:
        return RandomNumber('a', 'z');
    case CapitalLetter:
        return RandomNumber('A', 'Z');
    case SpecialCharacter: {
        string specialChars = "!@#$%^&*()_+-=[]{}|;:,.<>?/";
        return specialChars[RandomNumber(0, specialChars.length() - 1)];
    }
    case Digit:
        return RandomNumber('0', '9');
    default:
        return '?';  
    }
}

int main() {
    srand((unsigned)time(0));  

 
    cout << GenerateRandomChar(SmallLetter) << endl;
    cout << GenerateRandomChar(CapitalLetter) << endl;
    cout << GenerateRandomChar(SpecialCharacter) << endl;
    cout << GenerateRandomChar(Digit) << endl;

    return 0;
}



