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


