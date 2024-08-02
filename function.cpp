#include <iostream>
#include <string>

using namespace std;

void my_card() {
    string st_full_name, st_age, st_country;

    cout << "**************************" << endl;

    cout << "Enter your full name: ";
    getline(cin, st_full_name);

    cout << "Enter your age: ";
    getline(cin, st_age);  // Using getline to avoid issues with leftover newlines in the input buffer

    cout << "Where are you from: ";
    getline(cin, st_country);

    cout << "***************************" << endl;
    cout << "Name: " << st_full_name << endl;
    cout << "Age: " << st_age << endl;
    cout << "Country: " << st_country << endl;
}

int main() {
    my_card();
    return 0;
}
