#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int RandomNumber(int From, int To) {
    // Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLength) {
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}

void PrintArray(int arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int SumOFArry(int arr[100], int arrLength) {
    int sum = 0;
    for (int i = 0; i < arrLength; i++) {
        sum += arr[i];
    }
     
    return sum;
}
float averageOfArray(int arr[100], int arrLength) {
    return (float)SumOFArry(arr, arrLength) / arrLength;
}


int main() {
    
    srand((unsigned)time(NULL));

    int arr[100], arrLength;
    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);

    cout << "\navrege  Number is: ";
    cout << averageOfArray(arr, arrLength) << endl;

    return 0;
}
