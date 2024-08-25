#include <iostream>
#include <cstdlib>   
using namespace std;

int ReadNumber() {
    int Number;
    cout << "\nPlease enter a number: ";
    cin >> Number;
    return Number;
}

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

void addnumber(int Number, int arr[], int& arrLength) {
    for (int i = 0; i < Number; i++) {
        arr[i] = RandomNumber(1, 100);
    }
    arrLength = Number;  
}

void AddArrayElement(int Number, int arr[], int& arrLength) {
    arr[arrLength] = Number;
    arrLength++;
}

void copyarryusingaddarryelemnet(int source[], int destination[], int arrLength, int& copiedArrLength) {
    for (int i = 0; i < arrLength; i++) {
        AddArrayElement(source[i], destination, copiedArrLength);
    }
}

void PrintArray(int arr[], int arrLength) {
    for (int i = 0; i < arrLength; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int arr[100], copiedArr[100], arrLength = 0;

    int Number = ReadNumber();

    addnumber(Number, arr, arrLength);

    cout << "Original array: ";
    PrintArray(arr, arrLength);

    int copiedArrLength = 0;   
    copyarryusingaddarryelemnet(arr, copiedArr, arrLength, copiedArrLength);

    cout << "Copied array: ";
    PrintArray(copiedArr, copiedArrLength);

    return 0;
}
