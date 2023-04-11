#include <iostream>

#include "LargeNumberOperators.h"

int main() {
    std::string fNumber = "1419149194718947191345251418431974858637617198917470";
    std::string sNumber = "4133149813182948192891748311313431974817198961784731";
    std::string resultNumber;

    lno::Addition(fNumber, sNumber, resultNumber);
    std::cout << "Addition: " << std::endl;
    std::cout << resultNumber;

    lno::Subtraction(fNumber, sNumber, resultNumber);
    std::cout << "\nSubtraction: " << std::endl;
    std::cout << resultNumber;
    
    lno::Multiplication(fNumber, sNumber, resultNumber);
    std::cout << "\nMultiplication: " << std::endl;
    std::cout << resultNumber;

    return 0;
}