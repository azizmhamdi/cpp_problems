#include <iostream>
using namespace std;

float rusale_num(float value_num) {
    return value_num;
}

int main() {
    float value_num;
    cout << "Enter your num: ";
    cin >> value_num;

    int result;

    if (value_num == 1000000) {
        result = 1;
    }
    else if (value_num > 500000 && value_num < 1000000) {
        result = 2;
    }
    else if (value_num > 100000 && value_num <= 500000) {
        result = 3;
    }
    else if (value_num > 50000 && value_num <= 100000) {
        result = 4;
    }
    else if (value_num <= 50000) {
        result = 0;
    }
    else {
        result = -1;
    }

    if (result == -1) {
        cout << "Please enter another number" << endl;
    }
    else if (result == 0) {
        cout << "You can't have any percentage" << endl;
    }
    else {
        cout << "You have " << result << "% " << endl;
    }

    return 0;
}
