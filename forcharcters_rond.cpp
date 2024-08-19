 
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

 
void ckecknum(int& number) {
    do {
        cout << "Enter a positive number: ";
        cin >> number;
    } while (number < 0);
}

 
int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

 
void printnumber(int number) {
    
    for (int j = 1; j < number; j++) {
            cout << "the number is ["<<j<<"]";
        for (int i = 0; i < 4; i++) {
            char letter = RandomNumber('A', 'Z');
            cout << letter;
        }
        cout << endl;
    }
}

int main() {
     

    int number;
    ckecknum(number);   
    printnumber(number);  

    return 0;
}