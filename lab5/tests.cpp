#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Node.h"
#include "queue.h"
#include "stack.h"

TEST_CASE("Stacks")
{
    Stack *s = new Stack();
    s -> push(10);
    CHECK(s->top() == 10);
    Stack *s1 = new Stack();
    for(int i = 0; i < 20; i++)
    {
        s1->push(i);
    }
    CHECK(s1 -> top() == 19);
    CHECK(s1 -> is_empty() != 1);
    s1 -> pop();
    CHECK(s1 -> top() == 18);
    delete s1;
    s1 = nullptr;
    CHECK(s1 == nullptr);
}

TEST_CASE("Queues")
{
    Queue *q = new Queue();
    for(int i = 0; i < 4; i++)
    {
        q->enqueue(i);
    }
    CHECK(q -> is_full());
    CHECK(q -> front() == 0);
    for(int x = 0; x < 4; x++)
    {
        q->dequeue();
    }
    CHECK(q -> is_empty());
    
    Queue *q1 = new Queue();
    q1->enqueue(10);
    q1->enqueue(20);
    q1->enqueue(30);
    q1->enqueue(40);
    CHECK(q1 -> front() == 10);
    q1->dequeue();
    CHECK(q1 -> front() == 20);
    
}
