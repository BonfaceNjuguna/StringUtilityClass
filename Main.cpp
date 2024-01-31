#include "string.h"
#include <iostream>

int main() {
    String helloStr("Hello, ");

    String worldStr("World");

    String combineString = helloStr + worldStr;

    std::cout << combineString.CStr() << std::endl;

    return 0;
}