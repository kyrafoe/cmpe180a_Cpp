#include "mergeStrings.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string b ={"abc"};
    string a ={"defzzz"};
    string result ;

    mergeStrings(a,b,result);

    std::cout << result <<"\n";

    return 0;
}   
