#include <iostream>
#include "sorts.h"

int main()
{
    std::vector<int> v;
    for(int i = 0; i < 25; i++)
    {
        v.push_back(std::rand() % 100);
    }
    print(v);
    qsort2(v, 0, v.size() - 1);
    std::cout << "Sorted Array: \n";
    print(v);
}