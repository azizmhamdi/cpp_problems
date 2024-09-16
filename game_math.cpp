#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enoptions {
    easy = 1,
    med = 2,
    hard = 3,
    mix = 4
};

enum entype {
    add = 1,
    sub = 2,
    mul = 3,
    divOp = 4,  
    mixType = 5
};

 
class MathGame {
private:
    int drawCounter;
    int playerWinCounter;
    int computerWinCounter;
    enoptions difficulty;
    entype operation;
    int rounds;

public:
    MathGame() : drawCounter(0), playerWinCounter(0), computerWinCounter(0), rounds(0) {}

   
    int RandomNumber(int From, int To) {
        return rand() % (To - From + 1) + From;
    }

    
    void setRounds() {
        cout << "How many rounds do you want to play: ";
        cin >> rounds;
        cout << endl;
    }

  
    enoptions getDifficulty() {
        short choice;
        while (true) {
            cout << "\"start\" choose difficulty:" << endl;
            cout << "  easy = [1],  med = [2], hard = [3], mix = [4] :: " << endl;
            cin >> choice;

            if (choice >= 1 && choice <= 4) {
                return static_cast<enoptions>(choice);
            }
            else {
                cout << "Invalid choice. Please choose again." << endl;
            }
        }
    }

    
    entype getOperation() {
        short choice;
        while (true) {
            cout << "\"start\" choose operation:" << endl;
            cout << "  add = [1],  sub = [2], mul = [3], div = [4], mix = [5] :: " << endl;
            cin >> choice;

            if (choice >= 1 && choice <= 5) {
                return static_cast<entype>(choice);
            }
            else {
                cout << "Invalid choice. Please choose again." << endl;
            }
        }
    }

     
    void playRound() {
        int num1, num2, result, userAnswer;
        int randomOperation = 0;  

      
        switch (difficulty) {
        case easy:
            num1 = RandomNumber(1, 10);
            num2 = RandomNumber(1, 10);
            break;
        case med:
            num1 = RandomNumber(10, 50);
            num2 = RandomNumber(10, 50);
            break;
        case hard:
            num1 = RandomNumber(50, 100);
            num2 = RandomNumber(50, 100);
            break;
        case mix:
            num1 = RandomNumber(1, 100);
            num2 = RandomNumber(1, 100);
            break;
        default:
            cout << "Invalid difficulty choice! \n";
            return;
        }

       
        switch (operation) {
        case add:
            result = num1 + num2;
            cout << "What is " << num1 << " + " << num2 << "? ";
            break;
        case sub:
            result = num1 - num2;
            cout << "What is " << num1 << " - " << num2 << "? ";
            break;
        case mul:
            result = num1 * num2;
            cout << "What is " << num1 << " * " << num2 << "? ";
            break;
        case divOp:
            if (num2 != 0) {
                result = num1 / num2;
                cout << "What is " << num1 << " / " << num2 << "? ";
            }
            else {
                cout << "Division by zero error! \n";
                return;
            }
            break;
        case mixType:
            randomOperation = RandomNumber(1, 4);  
            operation = static_cast<entype>(randomOperation);
            return playRound();
        default:
            cout << "Invalid operation choice! \n";
            return;
        }

   
        cin >> userAnswer;
 
        if (userAnswer == result) {
            system("color 2F"); 
            cout << "Correct!" << endl;
            playerWinCounter++;
        }
        else {
            system("color 4F"); 
            cout << "Wrong! The correct answer was " << result << endl;
            computerWinCounter++;
        }

         
        system("color 07");
    }

    
    void startGame() {
        char playAgain;
        do {
            difficulty = getDifficulty();
            operation = getOperation();

        
            playerWinCounter = 0;
            computerWinCounter = 0;
 
            for (short i = 0; i < rounds; i++) {
                playRound();
            }
 
            cout << "\nGame Over! Final Results:\n";
            cout << "Player Wins: " << playerWinCounter << endl;
            cout << "Computer Wins: " << computerWinCounter << endl;

       
            cout << "Do you want to play again? (y/n): ";
            cin >> playAgain;

        } while (playAgain == 'y' || playAgain == 'Y');
    }
};

 
int main() {
    srand(time(0)); 
    MathGame game;
    game.setRounds();           
    game.startGame();  
}
