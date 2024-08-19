#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

enum rondamsgorps {
    small_letter,
    capital_latter,
    specil_charachter,
    digit_order
};

// Function to generate a random number within a given range
char RandomNumber(char min, char max) {
    return min + rand() % ((max - min) + 1);
}

char read_grops() {
    int chois;
   

    switch (chois) {
    case small_letter:
        return RandomNumber('a', 'z');
    case capital_latter:
        return RandomNumber('A', 'Z');
    case specil_charachter:
        return RandomNumber('!', '/');  // Example range for special characters
    case digit_order:
        return RandomNumber('0', '9');
    default:
        cout << "Invalid choice!" << endl;
        return '\0';  // Return null character for invalid choice
    }
}
int main() {
    int chois;
    int result=read_grops();
    cout << "Generated character: " << result << endl;
    return 0;
}
 