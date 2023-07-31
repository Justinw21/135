#pragma once
#include <vector>

#define STACK_ERR_EMPTY 1
#define STACK_ERR_FULL 2
#define STACK_ERR_OTHER 4

const int QUEUE_MAX_SIZE = 5;
class Queue
{
    private:
        std::vector<int> v;
        int head;
        int tail;
        int capacity;
    public:
        Queue();
        void enqueue(int i);
        int dequeue();
        int front();
        bool is_empty();
        bool is_full();
};
