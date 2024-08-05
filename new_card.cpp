#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Enum Definitions
enum enColors { red, green, blue, black };
enum enGender { male, female };
enum enMaritalStatus { single, married };

// Enum-to-String Conversion Functions
string colorToString(enColors color) {
    switch (color) {
    case red: return "red";
    case green: return "green";
    case blue: return "blue";
    case black: return "black";
    default: return "Unknown";
    }
}

string genderToString(enGender gender) {
    switch (gender) {
    case male: return "male";
    case female: return "female";
    default: return "Unknown";
    }
}

string maritalStatusToString(enMaritalStatus status) {
    switch (status) {
    case single: return "single";
    case married: return "married";
    default: return "Unknown";
    }
}

// Struct Definitions
struct stFullName {
    string name;
    string lastname;
    int number;
};

struct stAddress {
    string streetname;
    string buildingNo;
    string pobox;
    string zipcode;
};

struct stContactInfo {
    string phone;
    string mail;
    stAddress address;
};

struct strinfo {
    short age = 44;
    string city = "Amman";
    string country = "Jordan";
    short monthlySalary = 5000;
    short yearlySalary = 60000;
    enGender gender = male;
    enColors colors = green;
    enMaritalStatus maritalStatus = married;
};

struct stPerson {
    stContactInfo contactinfo;
    stFullName fullname;
    stAddress address;
    strinfo info;
};

// Functions to Read Enum Values
enColors readColor() {
    int choice;
    cout << "Select your favorite color:" << endl;
    cout << "0. Red" << endl;
    cout << "1. Green" << endl;
    cout << "2. Blue" << endl;
    cout << "3. Black" << endl;
    cout << "Enter your choice (0-3): ";
    cin >> choice;

    switch (choice) {
        case 0: return red;
        case 1: return green;
        case 2: return blue;
        case 3: return black;
        default: return red; // Default to red if invalid choice
    }
}

enGender readGender() {
    int choice;
    cout << "Select your gender:" << endl;
    cout << "0. Male" << endl;
    cout << "1. Female" << endl;
    cout << "Enter your choice (0-1): ";
    cin >> choice;

    switch (choice) {
        case 0: return male;
        case 1: return female;
        default: return male; // Default to male if invalid choice
    }
}

enMaritalStatus readMaritalStatus() {
    int choice;
    cout << "Select your marital status:" << endl;
    cout << "0. Single" << endl;
    cout << "1. Married" << endl;
    cout << "Enter your choice (0-1): ";
    cin >> choice;

    switch (choice) {
        case 0: return single;
        case 1: return married;
        default: return single; // Default to single if invalid choice
    }
}

// Function to Read Information
void readinfo(stPerson& person) {
    cout << "Enter your first name: ";
    cin >> person.fullname.name;
    cout << "Enter your last name: ";
    cin >> person.fullname.lastname;
    cout << "Enter your age: ";
    cin >> person.info.age;
    cout << "Enter your city: ";
    cin >> person.info.city;
    cout << "Enter your country: ";
    cin >> person.info.country;
    cout << "Enter your salary: ";
    cin >> person.info.monthlySalary;
    cout << "Enter your home number: ";
    cin >> person.fullname.number;
    cout << "Enter your phone number: ";
    cin >> person.contactinfo.phone;
    cout << "Enter your mail: ";
    cin >> person.contactinfo.mail;

    // Clear input buffer before getline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter your street name: ";
    getline(cin, person.contactinfo.address.streetname);
    cout << "Enter your buildingNo: ";
    getline(cin, person.contactinfo.address.buildingNo);
    cout << "Enter your pobox: ";
    cin >> person.contactinfo.address.pobox;
    cout << "Enter your zipcode: ";
    cin >> person.contactinfo.address.zipcode;

    // Read enum values
    person.info.gender = readGender();
    person.info.colors = readColor();
    person.info.maritalStatus = readMaritalStatus();
}

// Function to Print Information
void print_card(const stPerson& person) {
    cout << "***************************************" << endl;
    cout << "Name: " << person.fullname.name << " " << person.fullname.lastname << endl;
    cout << "Number: " << person.fullname.number << endl;
    cout << "Phone: " << person.contactinfo.phone << endl;
    cout << "Email: " << person.contactinfo.mail << endl;
    cout << "Street Name: " << person.contactinfo.address.streetname << endl;
    cout << "Building No: " << person.contactinfo.address.buildingNo << endl;
    cout << "P.O. Box: " << person.contactinfo.address.pobox << endl;
    cout << "Zip Code: " << person.contactinfo.address.zipcode << endl;
    cout << "Age: " << person.info.age << " Years." << endl;
    cout << "City: " << person.info.city << endl;
    cout << "Country: " << person.info.country << endl;
    cout << "Monthly Salary: " << person.info.monthlySalary << endl;
    cout << "Gender: " << genderToString(person.info.gender) << endl;
    cout << "Favorite Color: " << colorToString(person.info.colors) << endl;
    cout << "Marital Status: " << maritalStatusToString(person.info.maritalStatus) << endl;
    cout << "***************************************" << endl;
}

int main() {
    stPerson person1;
    readinfo(person1);
    print_card(person1);
    return 0;
}
