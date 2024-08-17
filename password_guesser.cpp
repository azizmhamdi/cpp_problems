#include <iostream>
#include <string>
using namespace std;

void guessPassword(string targetPassword) {
    int trial = 0;
    string guess;

    for (char i = 'A'; i <= 'Z'; i++) {
        for (char j = 'A'; j <= 'Z'; j++) {
            for (char k = 'A'; k <= 'Z'; k++) {
                guess = "";
                guess += i;
                guess += j;
                guess += k;
                trial++;
                cout << "Trial [" << trial << "]: " << guess << endl;

                if (guess == targetPassword) {
                    cout << "\nPassword is " << targetPassword << endl;
                    cout << "Found after " << trial << " Trial(s)" << endl;
                    return;
                }
            }
        }
    }
}

int main() {
    string password;
    cout << "Enter the 3-letter password to guess: ";
    cin >> password;

    guessPassword(password);

    return 0;
}
