# Large Number Arithmetic Operators Library
This **Large Number Arithmetic Operators Library** is designed to perform simple arithmatic 
operations on very large numbers. There are Addition, Subtraction, Multiplication, 
Division and Mode taking operations. It is easy to use and install 
as it consists of a single header file. 

## Notes
Currently it only does addition, subtraction and multiplication.

## Usage
```cpp
#include <iostream>
#include "LargeNumberOperators.h"

int main(){
    std::string fNumber = "1419149194718947191345251418431974858637617198917470";
    std::string sNumber = "4133149813182948192891748311313431974817198961784731";
    std::string resultNumber;

    lno::Addition(fNumber, sNumber, resultNumber);
    std::cout << "Addition: " << std::endl;
    std::cout << resultNumber;
    // 5552299007901895384236999729745406833454816160702201

    lno::Subtraction(fNumber, sNumber, resultNumber);
    std::cout << "\nSubtraction: " << std::endl;
    std::cout << resultNumber;
    // -2714000618464001001546496892881457116179581762867261
    
    lno::Multiplication(fNumber, sNumber, resultNumber);
    std::cout << "\nMultiplication: " << std::endl;
    std::cout << resultNumber;
    // 5865556229031347952083112353222631447227653248032658997355360056412540804700547998450422790872375150570

    return 0;
}
```
Usage Negative Numbers
```cpp
#include <iostream>
#include "LargeNumberOperators.h"

int main(){
    /*
    ==> It is sufficient to have a "-" sign at the beginning of the number
    */
    std::string fNumber = "-1419149194718947191345251418431974858637617198917470";
    std::string sNumber = "4133149813182948192891748311313431974817198961784731";
    std::string resultNumber;

    lno::Addition(fNumber, sNumber, resultNumber);
    std::cout << "Addition: " << std::endl;
    std::cout << resultNumber;
    // 2714000618464001001546496892881457116179581762867261

    lno::Subtraction(fNumber, sNumber, resultNumber);
    std::cout << "\nSubtraction: " << std::endl;
    std::cout << resultNumber;
    // -5552299007901895384236999729745406833454816160702201
    
    lno::Multiplication(fNumber, sNumber, resultNumber);
    std::cout << "\nMultiplication: " << std::endl;
    std::cout << resultNumber;
    // -5865556229031347952083112353222631447227653248032658997355360056412540804700547998450422790872375150570

    return 0;
}
```

This is not a professional library. You are responsible for use.