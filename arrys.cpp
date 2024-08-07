 #include <iostream>
#include <string>
using namespace std;

struct stinfo {
    string first_name;
    string last_name;
    int age;
    int phone;
};

void red_1prsone(stinfo& info) {
    cout << "Enter your first name: ";
    cin >> info.first_name;
    cout << "Enter your last name: ";
    cin >> info.last_name;
    cout << "Enter your age: ";
    cin >> info.age;
    cout << "Enter your phone: ";
    cin >> info.phone;
}

void print_1prsone(  stinfo& info) {
    cout << "First name: " << info.first_name << endl;
    cout << "Last name: " << info.last_name << endl;
    cout << "Age: " << info.age << endl;
    cout << "Phone: " << info.phone << endl;
}

void read2person(stinfo person[2]) {
    cout << "Enter information for the first person:\n";
    red_1prsone(person[0]);
    cout << "Enter information for the second person:\n";
    red_1prsone(person[1]);
}

void print2person(  stinfo person[2]) {
    cout << "\nInformation for the first person:\n";
    print_1prsone(person[0]);
    cout << "\nInformation for the second person:\n";
    print_1prsone(person[1]);
}

int main() {
    stinfo person[2];

    read2person(person);   
    print2person(person); 

    return 0;
}
