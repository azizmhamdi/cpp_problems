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