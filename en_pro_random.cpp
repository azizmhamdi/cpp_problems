#include <iostream>
#include <string>
#include <ctime>

using namespace std;

enum enCharType {
    CapitalLetter,
    LowercaseLetter,
    Digit
};

char GetRandomCharacter(enCharType CharType) {
     
    switch (CharType) {
    case enCharType::CapitalLetter:
        return static_cast<char>(rand() % (65 - 90 + 1)) + 65;  
    case enCharType::LowercaseLetter:
        return static_cast<char>(rand() % (97 - 122 + 1)) + 97;  
    case enCharType::Digit:
        return static_cast<char>(rand() % (48 - 57 + 1)) + 48;  
    default:
        
        return ' ';  
    }
}

int ReadPositiveNumber(string Message) {
    int Number = 0;
    do {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

string GenerateWord(enCharType CharType, short Length) {
    string Word;

    for (int i = 1; i <= Length; i++) {
        Word = Word + GetRandomCharacter(CharType);
    }
    return Word;
}

string GenerateKey() {
    string Key = "";

    Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4);

    return Key;
}

void GenerateKeys(short NumberOfKeys) {
    for (int i = 1; i <= NumberOfKeys; i++) {
        cout << "Key [" << i << "] : ";
        cout << GenerateKey() << endl;
    }
}

int main() {
     
    srand((unsigned)time(NULL));

    GenerateKeys(ReadPositiveNumber("Please enter how many keys to generate? \n"));

    return 0;
}