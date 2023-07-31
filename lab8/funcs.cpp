#include "funcs.h"
#include <vector>
#include <iostream>

void heapify(std::vector<int> &list, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if((list[left] > list[i]) && (left < n))
    {
        largest = left;
    }
    if((list[right] > list[largest]) && (right < n))
    {
        largest = right;
    }
    if(largest != i)
    {
        std::swap(list[i], list[largest]);
        heapify(list, n, largest);
    }
}

void heapsort(std::vector<int> &list)
{
    int size = list.size();
    for(int i = size/2-1; i >= 0; i--)
    {
        heapify(list, size, i);
    }
    for(int x = size-1; x > 0; x--)
    {
        std::swap(list[0], list[x]);
        heapify(list, x, 0);
    }
}

/*
void swap(int index1, int index2, std::vector<int> &list)
{
    int tmp = list[index1];
    list[index1] = list[index2];
    list[index2] = tmp;
}
*/