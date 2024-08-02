#include <iostream>
#include <string>

using namespace std;

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

struct stPerson {
    stContactInfo contactinfo;
    stFullName fullname;
    stAddress address;
};

enum enColors { red, green, blue, black };
enum enGender { male, female };
enum enMaritalStatus { single, married };

int main() {
    // Creating an instance of stPerson
    stPerson person;
    person.fullname.name = "Mohammed";
    person.fullname.lastname = "Abu-Hadhoud";
    person.fullname.number = 24582891;
    person.contactinfo.phone = "123456789";
    person.contactinfo.mail = "mohammed@example.com";
    person.contactinfo.address.streetname = "Some Street";
    person.contactinfo.address.buildingNo = "10";
    person.contactinfo.address.pobox = "1234";
    person.contactinfo.address.zipcode = "56789";
    person.address.streetname = "Some Street";
    person.address.buildingNo = "10";
    person.address.pobox = "1234";
    person.address.zipcode = "56789";

    short age = 44;
    string city = "Amman";
    string country = "Jordan";
    short monthlySalary = 5000;
    short yearlySalary = 60000;
    enGender gender = male;
    enColors colors = green;
    enMaritalStatus maritalStatus = married;

    // Printing the information
    cout << "***************************************" << endl;
    cout << "Name: " << person.fullname.name << " " << person.fullname.lastname << endl;
    cout << "Number: " << person.fullname.number << endl;
    cout << "Phone: " << person.contactinfo.phone << endl;
    cout << "Email: " << person.contactinfo.mail << endl;
    cout << "Street Name: " << person.contactinfo.address.streetname << endl;
    cout << "Building No: " << person.contactinfo.address.buildingNo << endl;
    cout << "P.O. Box: " << person.contactinfo.address.pobox << endl;
    cout << "Zip Code: " << person.contactinfo.address.zipcode << endl;
    cout << "Age: " << age << " Years." << endl;
    cout << "City: " << city << endl;
    cout << "Country: " << country << endl;
    cout << "Monthly Salary: " << monthlySalary << endl;
    cout << "Yearly Salary: " << yearlySalary << endl;
    cout << "Color: " << static_cast<int>(colors) << endl;
    cout << "Gender: " << static_cast<int>(gender) << endl;
    cout << "Marital Status: " << (maritalStatus == married ? "Married" : "Single") << endl;
    cout << "***************************************" << endl;

  
    float num = 100.55;
    cout << num << endl;
    string str_num = to_string(num);
    cout << str_num << endl;

    int chn_num = stoi(str_num.substr(0, str_num.find('.')));  
    cout << chn_num + 100 << endl;

    return 0;
}
