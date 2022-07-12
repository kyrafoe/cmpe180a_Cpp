#include "BigInt.h"
#include <iostream>


int main()
{
    std::vector<int> vector1{2};
    BigInt A(vector1);
    
    std::vector<char> vector2{'2','7'};
    BigInt B(vector2); 

    std::vector<char> vector7{'4','5','6'};
    BigInt H(vector7); 

    char charArray[] = {'7', '8'};
    BigInt C(charArray, 2);  

    char charArray2[] = {'4', '2', '5'};
    BigInt K(charArray2, 3);  

    std::cout << B-A <<"\n"; 

    return 0;
} 
