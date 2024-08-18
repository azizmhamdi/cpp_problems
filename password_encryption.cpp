#include <iostream>
#include <string>
using namespace std;

string readPassword(string& input) {
    cout << "Enter your password: " << endl;
    getline(cin, input);
    cout << "Password before encryption: " << input << endl;
    return input;
}

string encryptPassword(string& input) {
    string output = "";

    for (size_t i = 0; i < input.length(); i++) {
        
        char ch = input[i] + i;
        output += ch;
    }

    return output;
}
string dencryptPassword(string input) {
    string doutput = "";

    for (size_t i = 0; i < input.length(); i++) {
         
        char ch = input[i] - i;
        doutput += ch;
    }

    return doutput;
}

int main() {
    string password;
    readPassword(password);

    string encryptedPassword = encryptPassword(password);
    cout << "Password after encryption: " << encryptedPassword << endl;
   string encryptionpassword= dencryptPassword(encryptedPassword);
   cout << "Password before encryption: " << encryptionpassword;

    return 0;
}