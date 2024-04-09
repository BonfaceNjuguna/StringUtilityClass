#include "string.h"
#include <iostream>

int main() {
    String helloStr("Hello, ");
    String worldStr("World");
    String turkanaStr("Hello Turkana");
    String findAndReplaceString("This is a test string to be used for search and replace");

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
    std::cout << "Prepending 'Mr. ' is: " << helloStr.Prepend("Mr. ").CStr() << std::endl;

    //append
    std::cout << "Appending ' Bonface' is: " << helloStr.Append(" Bonface").CStr() << std::endl;

    //find
    size_t foundIndex = findAndReplaceString.Find("inputStr");
    if (foundIndex != SIZE_MAX) {
        std::cout << "Substring found at index: " << foundIndex << std::endl;
    }
    else {
        std::cout << "Substring not found." << std::endl;
    }

    //find from index
    size_t findIndex = findAndReplaceString.Find(10, "string");
    if (findIndex != SIZE_MAX) {
        std::cout << "Substring found at index: " << findIndex << std::endl;
    }
    else {
        std::cout << "Substring not found." << std::endl;
    }

    //write to console
    std::cout << "The first string is: ";
    worldStr.WriteToConsole();
    std::cout << std::endl;

    //replace
    turkanaStr.Replace("Turkana", "Kenya");
    std::cout << "The string after replacing 'Turkana' with 'Kenya' is: " << turkanaStr.CStr() << std::endl;

    //copy
    String copiedString = helloStr;
    std::cout << "Copied string is: " << copiedString.CStr() << std::endl;

    //operator overload equality
    if (helloStr == worldStr)
        std::cout << "The strings are equal." << std::endl;
    else
        std::cout << "The strings are not equal." << std::endl;

    //operator overload assignment
    String assignedString;
    assignedString = worldStr;
    std::cout << "Assigned string is: " << assignedString.CStr() << std::endl;

    //operator overload subscript
    std::cout << "Character at index 6 of helloStr is: " << helloStr[6] << std::endl;

    //operator overload inequality
    if (helloStr != worldStr)
        std::cout << "The strings are not equal." << std::endl;
    else
        std::cout << "The strings are equal." << std::endl;

    //operator overload less than
    if (helloStr < worldStr)
        std::cout << "helloStr is less than worldStr." << std::endl;
    else
        std::cout << "helloStr is not less than worldStr." << std::endl;

    //operator overload addition
    String addedString = helloStr + " Kabiru";
    std::cout << "Added string is: " << addedString.CStr() << std::endl;

    //operator overload addition assignment
    helloStr += " Kabiru";
    std::cout << "helloStr after addition assignment: " << helloStr.CStr() << std::endl;

    //read from console
    String inputString;
    std::cout << "Enter a string: ";
    inputString.ReadFromConsole();
    std::cout << "You entered: " << inputString.CStr() << std::endl;

    return 0;
}