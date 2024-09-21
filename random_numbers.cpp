#include <iostream>
#include <cstdlib>  
#include <ctime>   
using namespace std;

int generateRandom() {
    return rand() % 100 + 1;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    for (int row = 0; row < 3; row++) {    
        for (int col = 0; col < 3; col++) {   
            int result = generateRandom();
            printf("%6d", result);   
        }
        printf("\n");  
    }

    return 0;
}
