#include "string.h"
#include <iostream>

int main() {
    String helloStr("Hello, ");
    String worldStr("World");

    String combineString = helloStr + worldStr;

    std::cout << "The combined string is: " << combineString.CStr() << std::endl;
    std::cout << "The length of the combined string is: " << combineString.Length() << std::endl;
    std::cout << "The character at index 7 is: " << combineString.CharacterAt(7) << std::endl;
    std::cout << "The upper case of the combined string is: " << combineString.ToUpper().CStr() << std::endl;
    std::cout << "The lower case of the combined string is: " << combineString.ToLower().CStr() << std::endl;

    return 0;
}