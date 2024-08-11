#include <iostream>

using namespace std;

enum ennumbertype { odd = 1, even = 2 };

int readnumber() {
    int num;
    cout << "please enter your number :" << endl;
    cin >> num;
    return num;
}

ennumbertype checknumbertype(int num) {
    int result = num % 2;
    if (result == 0) {
        return ennumbertype::even;
    }
    else {
        return ennumbertype::odd;
    }
}

void printnumbertype(ennumbertype numbertype) {
    if (numbertype == ennumbertype::even) {
        cout << "your number type is even " << endl;
    }
    else {
        cout << "your number type is odd " << endl;
    }
}

int main() {
    printnumbertype(checknumbertype(readnumber()));
    return 0;
}
