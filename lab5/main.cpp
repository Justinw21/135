#include <iostream>
#include "Node.h"
#include "queue.h"
#include "stack.h"

int main()
{
    //Stacks
    Stack *s = new Stack();
    std::cout << "stack empty? " << s->is_empty() << "\n";
    std::cout << "top of empty stack? \n";
    try{
        s -> top();
    }
    catch(int e){
        std::cout << "Empty stack\n";
    }
    std::cout << "pop with empty sack? \n";
    try{
        s -> pop();
    }
    catch(int e){
        std::cout << "Empty stack\n";
    }
    std::cout << "Fill stack with 1,2,3,4,5\n";
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);
    s->push(5);
    std::cout << "top is : " << s->top() << "\n";
    s->pop();
    std::cout << "pop() so new top is : " << s->top() << "\n";
    //Queues
    Queue* q = new Queue();
    std::cout << "\nqueue empty? " << q->is_empty() << "\n";
    try {
        std::cout << "pushing 10,20,30,40,50" << "\n";
        q->enqueue(10);
        q->enqueue(20);
        q->enqueue(30);
        q->enqueue(40);
        q->enqueue(50);
    } catch (const char* e) {
        std::cout << "Queue is full!\n";
    }   

    std::cout << "Check front element: " << q->front() << "\n";
    return 0;
}