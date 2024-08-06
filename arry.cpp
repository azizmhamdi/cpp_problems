#include <iostream>
#include <string>
using namespace std;

void read_degree(int degree[3]) {
    cout << "Enter the first degree: " << endl;
    cin >> degree[0];
    cout << "Enter the second degree: " << endl;
    cin >> degree[1];
    cout << "Enter the third degree: " << endl;
    cin >> degree[2];
}

void print_degree(int degree[3]) {
    float avg_degree = (degree[0] + degree[1] + degree[2]) / 3.0;
    cout << "The average of your degrees is: " << avg_degree << endl;
}

int main() {
    int degree[3];
    read_degree(degree);
    print_degree(degree);

    return 0;
}