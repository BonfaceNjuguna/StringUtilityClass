#include "string.h"
#include <iostream>

int main() {
    String helloStr("Hello, ");
    String worldStr("World");

    String combineString = helloStr + worldStr;

    std::cout << "The combined string is: " << combineString.CStr() << std::endl;
    std::cout << "The length of the combined string is: " << combineString.Length() << std::endl;
    std::cout << "The character at index 5 is: " << combineString.CharacterAt(5) << std::endl;
    combineString.CharacterAt(5) = 'd';
    const char& ch = combineString.CharacterAt(5);
    std::cout << "The character at index 5 is: " << ch << std::endl;

    if (combineString.EqualTo("Hello, World"))
    {
        std::cout << "The combined string is equal to 'Hello, World'" << std::endl;
    }
    else
    {
        std::cout << "The combined string is not equal to 'Hello, World'" << std::endl;
    }

    std::cout << "The upper case of the combined string is: " << combineString.ToUpper().CStr() << std::endl;
    std::cout << "The lower case of the combined string is: " << combineString.ToLower().CStr() << std::endl;

    return 0;
}