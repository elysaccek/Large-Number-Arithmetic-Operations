# Large Number Arithmetic Operators Library
This **Large Number Arithmetic Operators Library** is designed to perform simple arithmatic 
operations on very large numbers. There are Addition, Subtraction, Multiplication, 
Division and Mode taking operations. It is easy to use and install 
as it consists of a single header file. 

## Notes
Currently it only does addition and multiplication. It only works with positive numbers.

## Usage
```cpp
#include <iostream>
#include "LargeNumberOperators.h"

int main(){
    std::string fNumber = "1419149194718947191345251418431974858637617198917470";
    std::string sNumber = "4133149813182948192891748311313431974817198917471";
    std::string resultNumber;

    lno::Addition(fNumber, sNumber, resultNumber);
    std::cout << "Addition: " << std::endl;
    std::cout << resultNumber;
    // 1423282344532130139538143166743288290612434397834941
    
    lno::Multiplication(fNumber, sNumber, resultNumber);
    std::cout << "\nMultiplication: " << std::endl;
    std::cout << resultNumber;
    // 5865556229031347952083112353222631447227653185144863333713313615933541320937572314020027757070118370

    return 0;
}
```

This is not a professional library. You are responsible for use.