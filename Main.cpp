#include <iostream>
#include "JavaToCppConverter.h"

int main() {
    JavaToCppConverter converter;
    std::string cppCode = converter.convertFile("Example.java");
    std::cout << cppCode << std::endl;
    return 0;
}
