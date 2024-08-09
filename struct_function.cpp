 #include <iostream>
#include <string>
using namespace std;
struct strinfo {
	string first_name;
	string last_name;
	int age;
	int phone;
};
void readinfo(strinfo &info) {
 
	cout << "please enter your first name :" << endl;
	cin >> info.first_name;
	cout << "please enter your last name :" << endl;
	cin >> info.last_name;
	cout << "please enter your age :" << endl;
	cin >> info.age;
	cout << "enetr your phone number "<<endl;
	cin >> info.phone;


} 
void printinfo(strinfo info) {
	cout << "**************************" << endl;
	cout << "first name :" << info.first_name << endl;
	cout << "last name :" << info.last_name << endl;
	cout << "age :" << info.age << endl;
	cout << "phone :" << info.phone << endl;
	cout << "****************************" << endl;
}
int main() {
	strinfo strinfo1;
	readinfo(strinfo1);
	printinfo(strinfo1);
}




























#include <iostream>
#include <string>

using namespace std;

struct strInfo {
    string name;
    int age;
    string phoneNumber;
    string email;
};

void ReadInfo(strInfo& Info) {
    cout << "Enter name: ";
    getline(cin, Info.name);
    cout << "Enter age: ";
    cin >> Info.age;
    cin.ignore();  

    cout << "Enter phone number: ";
    getline(cin, Info.phoneNumber);

    cout << "Enter email: ";
    getline(cin, Info.email);
}

void PrintInfo(strInfo Info) {
    cout << "Name: " << Info.name << "\n";
    cout << "Age: " << Info.age << "\n";
    cout << "Phone Number: " << Info.phoneNumber << "\n";
    cout << "Email: " << Info.email << "\n";
}

void ReadPersonsInfo(strInfo Persons[100], int sum;) {
     
   
    for (int i = 0; i < sum - 1; i++) {
        ReadInfo(Persons[i]);
        


    }
}

void PrintPersonsInfo(strInfo Persons[100], int sum;) {
    for (int i = 0; i < sum - 1; i++) {
        PrintInfo(Persons[i]);



    }
    cout << "\n*************************\n";
    
}

int main() {
    strInfo persons[100];
    int sum;
    cout << "Enter the number of people (max length 100): ";
    cin >> sum;
  j

    ReadPersonsInfo(persons, sum);
    PrintPersonsInfo(persons, sum);

    return 0;
}