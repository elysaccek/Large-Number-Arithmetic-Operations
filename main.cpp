#include <iostream>

#include "LargeNumberOperators.h"

int main() {
    std::string fNumber = "1419149194718947191345251418431974858637617198917470";
    std::string sNumber = "4133149813182948192891748311313431974817198961784731";
    std::string resultNumber;

    lno::Addition(fNumber, sNumber, resultNumber);
    std::cout << "Addition: " << std::endl;
    std::cout << resultNumber;
    
    lno::Multiplication(fNumber, sNumber, resultNumber);
    std::cout << "\nMultiplication: " << std::endl;
    std::cout << resultNumber;

    lno::Subtraction(fNumber, sNumber, resultNumber);
    std::cout << "\nSubtraction: " << std::endl;
    std::cout << resultNumber;

    return 0;
}

// https://stackoverflow.com/questions/40797366/dynamic-memory-resize-char-array
char* Resize(char*& old,long int length,long int resize_to)
{
    char* new_ptr;
    new_ptr = new char[ resize_to ];
    long int least = ( length < resize_to ) ? length : resize_to;
    for(long int i = 0;i < least ; ++i)
        new_ptr [i] = old[i];
    delete [] old;
    old = nullptr;
    return new_ptr;
}
