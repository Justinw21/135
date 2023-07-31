#include "funcs.h"
#include<iostream>

int main()
{
    std::vector<int> d1 = {2,3,6,5,4};
    std::cout << "original: " << std::endl;
    for(int i = 0; i < d1.size(); i++)
    {
        std::cout << d1[i] << ", ";
    }
    std::cout << "\nsorted: " << std::endl;
    heapsort(d1);
    for(int i = 0; i < d1.size(); i++)
    {
        std::cout << d1[i] << ", ";
    }
    return 0;
}


