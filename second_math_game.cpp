#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Enumeration for question levels
enum enQuestionsLevel {
    EasyLevel = 1,
    MedLevel = 2,
    HardLevel = 3,
    Mix = 4
};

// Enumeration for operation types
enum enOperationType {
    Add = 1,
    Sub = 2,
    Mult = 3,
    Div = 4,
    MixOp = 5
};

// Get the symbol for the operation type
string GetOpTypeSymbol(enOperationType OpType) {
    switch (OpType) {
        case Add: return "+";
        case Sub: return "-";
        case Mult: return "x";
        case Div: return "/";
        default: return "Mix";
    }
}

// Get the text for the question level
string GetQuestionLevelText(enQuestionsLevel QuestionLevel) {
    string arrQuestionLevelText[4] = { "Easy", "Med", "Hard", "Mix" };
    return arrQuestionLevelText[QuestionLevel - 1];
}

// Generate a random number between From and To
int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

// Set the screen color based on correctness of the answer
void SetScreenColor(bool Right) {
    if (Right)
        system("color 2F"); // Green
    else {
        system("color 4F"); // Red
        cout << "\a"; // Bell sound
    }
}

// Read the number of questions
short ReadHowManyQuestions() {
    short NumberOfQuestions;
    do {
        cout << "How many questions do you want to answer? ";
        cin >> NumberOfQuestions;
    } while (NumberOfQuestions < 1 || NumberOfQuestions > 10);
    return NumberOfQuestions;
}

// Read the question level
enQuestionsLevel ReadQuestionsLevel() {
    short QuestionLevel = 0;
    do {
        cout << "Enter question level [1] Easy, [2] Med, [3] Hard, [4] Mix: ";
        cin >> QuestionLevel;
    } while (QuestionLevel < 1 || QuestionLevel > 4);
    return (enQuestionsLevel) QuestionLevel;
}

// Read the operation type
enOperationType ReadOpType() {
    short OpType;
    do {
        cout << "Enter operation type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix: ";
        cin >> OpType;
    } while (OpType < 1 || OpType > 5);
    return (enOperationType) OpType;
}

// Structure for a question
struct stQuestion {
    int Number1 = 0;
    int Number2 = 0;
    enOperationType OperationType;
    enQuestionsLevel QuestionLevel;
    int CorrectAnswer = 0;
    int PlayerAnswer = 0;
    bool AnswerResult = false;
};

// Structure for the quiz
struct stQuizz {
    stQuestion QuestionList[100];
    short NumberOfQuestions;
    enQuestionsLevel QuestionsLevel;
    enOperationType OpType;
    short NumberOfWrongAnswers = 0;
    short NumberOfRightAnswers = 0;
    bool isPass = false;
};

// Perform the calculation based on the operation type
int SimpleCalculator(int Number1, int Number2, enOperationType OpType) {
    switch (OpType) {
        case Add: return Number1 + Number2;
        case Sub: return Number1 - Number2;
        case Mult: return Number1 * Number2;
        case Div: return Number1 / Number2;
        default: return Number1 + Number2;
    }
}

// Get a random operation type
enOperationType GetRandomOperationType() {
    int Op = RandomNumber(1, 4);
    return (enOperationType) Op;
}

// Generate a question based on the level and operation type
stQuestion GenerateQuestion(enQuestionsLevel QuestionLevel, enOperationType OpType) {
    stQuestion Question;
    if (QuestionLevel == Mix)
        QuestionLevel = (enQuestionsLevel) RandomNumber(1, 3);
    if (OpType == MixOp)
        OpType = GetRandomOperationType();

    Question.OperationType = OpType;
    switch (QuestionLevel) {
        case EasyLevel:
            Question.Number1 = RandomNumber(1, 10);
            Question.Number2 = RandomNumber(1, 10);
            break;
        case MedLevel:
            Question.Number1 = RandomNumber(10, 50);
            Question.Number2 = RandomNumber(10, 50);
            break;
        case HardLevel:
            Question.Number1 = RandomNumber(50, 100);
            Question.Number2 = RandomNumber(50, 100);
            break;
    }
    Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
    Question.QuestionLevel = QuestionLevel;
    return Question;
}

// Generate questions for the quiz
void GenerateQuizzQuestions(stQuizz& Quizz) {
    for (short Question = 0; Question < Quizz.NumberOfQuestions; Question++) {
        Quizz.QuestionList[Question] = GenerateQuestion(Quizz.QuestionsLevel, Quizz.OpType);
    }
}

// Read the answer from the user
int ReadQuestionAnswer() {
    int Answer;
    cin >> Answer;
    return Answer;
}

// Print the question
void PrintTheQuestion(stQuizz& Quizz, short QuestionNumber) {
    cout << "\nQuestion [" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestions << "] \n\n";
    cout << Quizz.QuestionList[QuestionNumber].Number1 << " ";
    cout << GetOpTypeSymbol(Quizz.QuestionList[QuestionNumber].OperationType) << " ";
    cout << Quizz.QuestionList[QuestionNumber].Number2 << endl;
    cout << "_________" << endl;
}

// Check the answer and update quiz results
void CorrectTheQuestionAnswer(stQuizz& Quizz, short QuestionNumber) {
    if (Quizz.QuestionList[QuestionNumber].PlayerAnswer != Quizz.QuestionList[QuestionNumber].CorrectAnswer) {
        Quizz.QuestionList[QuestionNumber].AnswerResult = false;
        Quizz.NumberOfWrongAnswers++;
        cout << "Wrong Answer :-( \n";
        cout << "The right answer is: " << Quizz.QuestionList[QuestionNumber].CorrectAnswer << "\n";
    } else {
        Quizz.QuestionList[QuestionNumber].AnswerResult = true;
        Quizz.NumberOfRightAnswers++;
        cout << "Right Answer :-) \n";
    }
    cout << endl;
    SetScreenColor(Quizz.QuestionList[QuestionNumber].AnswerResult);
}

// Ask and correct answers for the list of questions
void AskAndCorrectQuestionListAnswers(stQuizz& Quizz) {
    for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestions; QuestionNumber++) {
        PrintTheQuestion(Quizz, QuestionNumber);
        Quizz.QuestionList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();
        CorrectTheQuestionAnswer(Quizz, QuestionNumber);
    }
    Quizz.isPass = (Quizz.NumberOfRightAnswers >= Quizz.NumberOfWrongAnswers);
}

// Get the final results text
string GetFinalResultsText(bool Pass) {
    return Pass ? "PASS :-)" : "Fail :-(";
}

// Print the quiz results
void PrintQuizzResults(stQuizz Quizz) {
    cout << "\n______________________________\n\n";
    cout << "Final Results: " << GetFinalResultsText(Quizz.isPass) << "\n";
    cout << "______________________________\n\n";
    cout << "Number of Questions: " << Quizz.NumberOfQuestions << endl;
    cout << "Questions Level    : " << GetQuestionLevelText(Quizz.QuestionsLevel) << endl;
    cout << "OpType             : " << GetOpTypeSymbol(Quizz.OpType) << endl;
    cout << "Number of Right Answers: " << Quizz.NumberOfRightAnswers << endl;
    cout << "Number of Wrong Answers: " << Quizz.NumberOfWrongAnswers << endl;
    cout << "______________________________\n";
}

// Play the math game
void PlayMathGame() {
    stQuizz Quizz;
    Quizz.NumberOfQuestions = ReadHowManyQuestions();
    Quizz.QuestionsLevel = ReadQuestionsLevel();
    Quizz.OpType = ReadOpType();
    GenerateQuizzQuestions(Quizz);
    AskAndCorrectQuestionListAnswers(Quizz);
    PrintQuizzResults(Quizz);
}

// Reset the screen
void ResetScreen() {
    system("cls");
    system("color 0F");
}

// Start the game loop
void StartGame() {
    char PlayAgain = 'Y';
    do {
        ResetScreen();
        PlayMathGame();
        cout << endl << "Do you want to play again? Y/N? ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

// Main function
int main() {
    srand((unsigned)time(NULL)); // Seed the random number generator
    StartGame();
    return 0;
}
