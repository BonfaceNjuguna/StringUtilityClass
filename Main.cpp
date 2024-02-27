#include "string.h"
#include <iostream>

int main() {
    String helloStr("Hello, ");
    String worldStr("World");

    //concatenation
    String combineString = helloStr + worldStr;

    //output of the combined string
    std::cout << "The combined string is: " << combineString.CStr() << std::endl;

    //length of the combined string
    std::cout << "The length of the combined string is: " << combineString.Length() << std::endl;

    //character at index 5
    std::cout << "The character at index 5 of the combined string is: " << combineString.CharacterAt(5) << std::endl;


    //check if combined string is equal to "Hello, World"
    if (combineString.EqualTo("Hello, World"))
        std::cout << "The combined string is equal to 'Hello, World'" << std::endl;
    else
        std::cout << "The combined string is not equal to 'Hello, World'" << std::endl;

    //convert to upper and lower case
    std::cout << "The upper case of the combined string is: " << combineString.ToUpper().CStr() << std::endl;
    std::cout << "The lower case of the combined string is: " << combineString.ToLower().CStr() << std::endl;

    //prepend
    std::cout << "Prepending 'Mr. ' is: " << combineString.Prepend("Mr. ").CStr() << std::endl;

    //append
    std::cout << "Appending ' Bonface' is: " << combineString.Append(" Bonface").CStr() << std::endl;

    //read from console
    std::cout << "Enter a string: ";
    combineString.ReadFromConsole();
    std::cout << "The string entered is: " << combineString.CStr() << std::endl;

    //write to console
    std::cout << "The first string is: ";
    helloStr.WriteToConsole();
    std::cout << std::endl;

    //find
    std::cout << "The index of 'Bonface' in the combined string is: " << combineString.Find("Bonface") << std::endl;

    return 0;
}