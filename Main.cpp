#include "string.h"
#include <iostream>

int main() {
    String helloStr("Hello, ");
    String worldStr("World");
    String turkanaStr("Hello Turkana");
    String myString("This is a test string to be used for search and replace");

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

    //read from console
    std::cout << "Enter a string to find: " << std::endl;
    String inputStr;
    inputStr.ReadFromConsole();

    std::cout << "Searching for " << inputStr.CStr() << " ..." << std::endl;

    if (myString.Find(inputStr) != String::npos)
    {
        std::cout << "Enter a string for replacement: " << std::endl;
        String replaceStr;
        replaceStr.ReadFromConsole();

        std::cout << "Replacing " << inputStr.CStr() << " with " << replaceStr.CStr() << " ..." << std::endl;
        myString.Replace(inputStr, replaceStr);
        std::cout << "The string after replacing is: " << myString.CStr() << std::endl;
    }
    else 
    {
        std::cout << "The string was not found" << std::endl;
    }

    //write to console
    std::cout << "The first string is: ";
    worldStr.WriteToConsole();
    std::cout << std::endl;

    //find and replace
    std::cout << "The string after replacing 'Turkana' with 'Kenya' is: " << turkanaStr.Replace("Turkana", "Kenya").CStr() << std::endl;

    return 0;
}