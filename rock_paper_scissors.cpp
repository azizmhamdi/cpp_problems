 
  
 #include <iostream>
#include <string>
#include <cstdlib>  
#include <ctime>    
using namespace std;

enum enoptions {
    stone = 1,
    paper = 2,
    scissor = 3
};

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

enoptions startply() {
    short choice;
    cout << "\"start\" choose :" << endl;
    cout << "  stone =[1],  paper = [2] , scissor = [3] :: " << endl;
    cin >> choice;

    switch (choice) {
    case stone:
        return stone;
    case paper:
        return paper;
    case scissor:
        return scissor;
    default:
        cout << "Invalid choice. Please choose again." << endl;
        return static_cast<enoptions>(-1);
    }
}

void attackk(short choice, enoptions pcchoice, int& drawCounter, int& playerWinCounter, int& computerWinCounter) {
    if (choice == pcchoice) {
        cout << "It's a draw! \a\n";
        system("color 6f");
        ++drawCounter;
    }
    else if ((choice == stone && pcchoice == scissor) ||
        (choice == paper && pcchoice == stone) ||
        (choice == scissor && pcchoice == paper)) {
        cout << "You win! \a\n";
        system("color 2f");
        ++playerWinCounter;
    }
    else {
        cout << "Computer wins! \a\n";
        system("color 4f");
        ++computerWinCounter;
    }
}

void checkuser() {
    int tryAgain = 1;
    while (tryAgain) {
        int drawCounter = 0;
        int playerWinCounter = 0;
        int computerWinCounter = 0;

        cout << "Enter the number of rounds you want to play: ";
        int number;
        cin >> number;

        for (int i = 0; i < number; i++) {
            enoptions choice = startply();
            if (choice == static_cast<enoptions>(-1)) {
                cout << "Invalid choice. Please try again." << endl;
                i--; // Repeat the current round
                continue;
            }

            enoptions pcchoice = static_cast<enoptions>(RandomNumber(1, 3));

            cout << "PC chose: ";
            switch (pcchoice) {
            case stone:
                cout << "stone\n";
                break;
            case paper:
                cout << "paper\n";
                break;
            case scissor:
                cout << "scissor\n";
                break;
            }

            attackk(choice, pcchoice, drawCounter, playerWinCounter, computerWinCounter);
        }

        cout << "Results: " << endl;
        cout << "Draws: " << drawCounter << endl;
        cout << "Player Wins: " << playerWinCounter << endl;
        cout << "Computer Wins: " << computerWinCounter << endl;

        cout << "Do you want to play again? (y/n): ";
        char response;
        cin >> response;
        if (response == 'n' || response == 'N') {
            tryAgain = 0;
        }
    }
}

int main() {
    srand(static_cast<unsigned>(time(0))); 
    checkuser();
    return 0;
}
