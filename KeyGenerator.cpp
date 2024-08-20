#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

enum enCharType {
    SmallLetter = 1,
    CapitalLetter = 2,
    SpecialCharacter = 3,
    Digit = 4
};

int RandomNumber(int From, int To) {
     
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

char GetRandomCharacter(enCharType CharType) {
    switch (CharType) {
    case enCharType::SmallLetter: {
        return char(RandomNumber(97, 122));
    }
    case enCharType::CapitalLetter: {
        return char(RandomNumber(65, 90));
    }
    case enCharType::SpecialCharacter: {
        return char(RandomNumber(33, 47));
    }
    case enCharType::Digit: {
        return char(RandomNumber(48, 57));
    }
    default: {
        return ' ';
    }
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
    for (int i = 0; i < Length; i++) {
        Word += GetRandomCharacter(CharType);
    }
    return Word;
}

string GenerateKey() {
    string Key = "";
    Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key += GenerateWord(enCharType::CapitalLetter, 4);
    return Key;
}

void GenerateKeys(short NumberOfKeys) {
    for (int i = 1; i <= NumberOfKeys; i++) {
        cout << "Key [" << i << "] : " << GenerateKey() << endl;
    }
}

int main() {
     
    srand((unsigned)time(NULL));
    GenerateKeys(ReadPositiveNumber("Please enter how many keys to generate?\n"));
    return 0;
}
