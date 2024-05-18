//#include "String.h"
//#include <iostream>
//#include <fstream>
//#include <ctime>
//#include <iomanip>
//#include <string>
//
////log test results to a file
//static void logTestResult(const std::string& testName, bool passed, std::ofstream& logFile, int& successfulTests) {
//    logFile << testName << " " << (passed ? "Successful" : "Failed") << std::endl;
//    if (passed) successfulTests++;
//}
//
//int main() {
//    std::ofstream logFile("log.txt", std::ios::app);
//
//    std::time_t t = std::time(nullptr);
//    std::tm tm;
//    localtime_s(&tm, &t);
//    char buffer[26];
//    asctime_s(buffer, sizeof buffer, &tm);
//
//    logFile << "\nDate: " << std::put_time(&tm, "%d/%m/%Y") << " Time: " << std::put_time(&tm, "%H:%M:%S") << std::endl;
//
//    String helloStr("Hello, ");
//    String worldStr("World");
//    String turkanaStr("Hello Turkana");
//    String findAndReplaceString("This is a test string to be used for search and replace");
//
//    int totalTests = 0;
//    int successfulTests = 0;
//
//    // Test concatenation
//    totalTests++;
//    String combineString = helloStr + worldStr;
//    logTestResult("Test " + std::to_string(totalTests) + " Concatenation", combineString.EqualTo("Hello, World"), logFile, successfulTests);
//
//    // Test length of the combined string
//    totalTests++;
//    logTestResult("Test " + std::to_string(totalTests) + " Length", combineString.Length() == 12, logFile, successfulTests);
//
//    // Test character at index
//    totalTests++;
//    logTestResult("Test " + std::to_string(totalTests) + " CharacterAt", combineString.CharacterAt(0) == 'H', logFile, successfulTests);
//
//    // Test string equality
//    totalTests++;
//    logTestResult("Test " + std::to_string(totalTests) + " EqualTo", combineString.EqualTo("Hello, World"), logFile, successfulTests);
//
//    // Test upper and lower case
//    totalTests++;
//    logTestResult("Test " + std::to_string(totalTests) + " ToUpper", combineString.ToUpper().EqualTo("HELLO, WORLD"), logFile, successfulTests);
//    totalTests++;
//    logTestResult("Test " + std::to_string(totalTests) + " ToLower", combineString.ToLower().EqualTo("hello, world"), logFile, successfulTests);
//
//    // Test prepend
//    totalTests++;
//    logTestResult("Test " + std::to_string(totalTests) + " Prepend", helloStr.Prepend("Mr. ").EqualTo("Mr. Hello, "), logFile, successfulTests);
//
//    // Test append
//    totalTests++;
//    logTestResult("Test " + std::to_string(totalTests) + " Append", helloStr.Append(" Bonface").EqualTo("Mr. Hello,  Bonface"), logFile, successfulTests);
//
//    // Test find
//    totalTests++;
//    size_t foundIndex = findAndReplaceString.Find("search");
//    logTestResult("Test " + std::to_string(totalTests) + " Find", foundIndex != SIZE_MAX, logFile, successfulTests);
//
//    // Test find from index
//    totalTests++;
//    size_t findIndex = findAndReplaceString.Find(10, "string");
//    logTestResult("Test " + std::to_string(totalTests) + " FindFromIndex", findIndex != SIZE_MAX, logFile, successfulTests);
//
//    // Test replace
//    totalTests++;
//    turkanaStr.Replace("Hello", "Hi");
//    logTestResult("Test " + std::to_string(totalTests) + " Replace", turkanaStr.EqualTo("Hi Turkana"), logFile, successfulTests);
//
//    // Test copy
//    totalTests++;
//    String copiedString = helloStr;
//    logTestResult("Test " + std::to_string(totalTests) + " Copy", copiedString.EqualTo(helloStr), logFile, successfulTests);
//
//    // Test operator overload equality
//    totalTests++;
//    logTestResult("Test " + std::to_string(totalTests) + " Operator==", helloStr == helloStr, logFile, successfulTests);
//
//    // Test operator overload assignment
//    totalTests++;
//    String smallString("This is smaller");
//    String largeString("This is a larger string to test assignment");
//    smallString = largeString;
//    logTestResult("Test " + std::to_string(totalTests) + " Operator=", smallString.Length() == largeString.Length(), logFile, successfulTests);
//
//    // Test operator overload subscript
//    totalTests++;
//    logTestResult("Test " + std::to_string(totalTests) + " Operator[]", helloStr[0] == 'M', logFile, successfulTests);
//
//    // Test operator overload inequality
//    totalTests++;
//    logTestResult("Test " + std::to_string(totalTests) + " Operator!=", helloStr != worldStr, logFile, successfulTests);
//
//    // Test operator overload less than
//    totalTests++;
//    logTestResult("Test " + std::to_string(totalTests) + " Operator<", helloStr < worldStr, logFile, successfulTests);
//
//    // Test operator overload addition
//    totalTests++;
//    String addedString = helloStr + " Kabiru";
//    logTestResult("Test " + std::to_string(totalTests) + " Operator+", addedString.EqualTo("Mr. Hello,  Bonface Kabiru"), logFile, successfulTests);
//
//    // Test operator overload addition assignment
//    totalTests++;
//    helloStr += " Kabiru";
//    logTestResult("Test " + std::to_string(totalTests) + " Operator+=", helloStr.EqualTo("Mr. Hello,  Bonface Kabiru"), logFile, successfulTests);
//
//    // Calculate percentage of successful tests
//    double successPercentage = (static_cast<double>(successfulTests) / totalTests) * 100;
//
//    // successful percentage
//    logFile << "Successful " << std::fixed << std::setprecision(2) << successPercentage << "%" << std::endl;
//
//    logFile.close();
//
//    return 0;
//}