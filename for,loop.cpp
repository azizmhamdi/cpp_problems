#include <iostream>
#include <string>
using namespace std;

void readarrydata(int arr[100], int& length) {
    cout << "Enter the number of elements (1 to 100): ";
    cin >> length;
    for (int i = 0; i < length; i++) {
        cout << "Enter your number [" << i + 1 << "]: ";
        cin >> arr[i];
    }
}

void printinfo(int arr[100], int length) {
    cout << "You entered the following numbers:" << endl;
    for (int i = 0; i < length; i++) {
        cout << "Number [" << i + 1 << "]: " << arr[i] << endl;
    }
}

int calcutearr(int arr[100], int length) {
    int sum = 0; // Initialize sum to 0
    for (int i = 0; i < length; i++) {
        sum += arr[i];
    }
    return sum;
}

float calculteaverge(int arr[100], int length) {
    return (float)calcutearr(arr, length) / length;
}

int main() {
    int arr[100], length;
    readarrydata(arr, length);
    printinfo(arr, length);
    
    cout << "******************************************" << endl;
    cout << "Sum of the elements: " << calcutearr(arr, length) << endl;
    cout << "Average of the elements: " << calculteaverge(arr, length) << endl;

    return 0;
}
