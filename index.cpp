#include <iostream>
#include <string>

int main() {
    std::string string1;
    int string2, string3;

 
    std::cout << "Please enter String1?\n";
    std::getline(std::cin, string1);

    std::cout << "Please Enter String2?\n";
    std::cin >> string2;

    std::cout << "Please Enter String3?\n";
    std::cin >> string3;

 
    std::cout << "***************************\n";
 
    int length = string1.length();
    std::cout << "The Length of String1 is " << length << "\n";

 
    std::cout << "Characters at 0, 2, 4, 7 are: ";
    if (length > 0) std::cout << string1[0] << " ";
    if (length > 2) std::cout << string1[2] << " ";
    if (length > 4) std::cout << string1[4] << " ";
    if (length > 7) std::cout << string1[7] << " ";
    std::cout << "\n";
 
    std::cout << "Concatenating String2 and String3 = " << std::to_string(string2) + std::to_string(string3) << "\n";

  
    std::cout << string2 << " * " << string3 << " = " << string2 * string3 << "\n";

    return 0;
}
