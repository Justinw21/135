#include "queue.h"
#include <iostream>

Queue::Queue()
{
    v.resize(QUEUE_MAX_SIZE);
    head = 0;
    tail = 0;
    capacity = QUEUE_MAX_SIZE;
}

void Queue::enqueue(int i)
{
    if(is_full())
    {
        throw "Queue is full";
    }
    v[tail] = i;
    tail++;
    tail %= capacity;
}

int Queue::dequeue()
{
    if(is_empty()){
        throw "Queue is empty";
    }
    int i = v[head];
    head++;
    head %= capacity;

    return i;
}

int Queue::front()
{
    if(is_empty())
    {
        throw "Queue has no front";
    }
    return v[head];
}

bool Queue::is_empty()
{
    return head == tail;
}

bool Queue::is_full()
{
    return (tail + 1) % capacity == head;
}
