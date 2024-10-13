// Doubly ended queue
#include <iostream>
using namespace std;

class Queue
{
public:
    int size;
    int f;
    int r;
    int *arr;
    void enqueueFront(Queue *q, int value);
    void enqueueLast(Queue *q, int value);
    int isFull(Queue *q);
    int isEmpty(Queue *q);
    int dequeueFront(Queue *q);
    int dequeueLast(Queue *q);
    void dequeDisplay(Queue *q);
};

int Queue::isFull(Queue *q)
{
    if ((q->f == 0 && q->r == q->size - 1) || q->f == q->r + 1)
    {
        return 1;
    }
    return 0;
}

int Queue::isEmpty(Queue *q)
{
    if (q->f == -1)
    {
        return 1;
    }
    return 0;
}

void Queue::enqueueFront(Queue *q, int value)
{
    if (isFull(q))
    {
        cout << "This Queue is Full" << endl;
        return;
    }
    if (q->f == -1)
    {
        q->f = 0;
        q->r = 0;
    }
    else if (q->f == 0)
    {
        q->f = size - 1;
    }
    else
    {
        q->f = q->f - 1;
    }
    q->arr[q->f] = value;
}

void Queue::enqueueLast(Queue *q, int value)
{
    if (isFull(q))
    {
        cout << "This Queue is Full" << endl;
        return;
    }
    if (q->r == -1)
    {
        q->f = 0;
        q->r = 0;
    }
    else if (q->r == size - 1)
    {
        q->r = 0;
    }
    else
    {
        q->r = q->r + 1;
    }
    q->arr[q->r] = value;
}

int Queue::dequeueFront(Queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        cout << "This Queue is Empty" << endl;
    }
    a = q->arr[q->f];
    if (q->f == q->r)
    {
        q->f = -1;
        q->r = -1;
    }
    else if (q->f == size - 1)
    {
        q->f = 0;
    }
    else
    {
        q->f = q->f + 1;
    }
    return a;
}

int Queue::dequeueLast(Queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        cout << "This Queue is Empty" << endl;
    }
    a = q->arr[q->r];
    if (q->f == q->r)
    {
        q->f = -1;
        q->r = -1;
    }
    else if (q->r == 0)
    {
        q->r = size - 1;
    }
    else
    {
        q->r = q->r - 1;
    }
    return a;
}

void Queue::dequeDisplay(Queue *q)
{
    if (isEmpty(q))
    {
        cout << "This Queue is Empty" << endl;
    }
    int j = 0;
    int i = q->f;
    while (1)
    {
        j++;
        cout << "element " << j << ":: " << q->arr[i] << endl;
        if (i == q->r)
        {
            break;
        }
        i = (i + 1) % q->size;
    }
    cout << endl;
}

int main()
{
    cout << "***************DEqueue (Doubly Ended queue) using Array***************" << endl;
    Queue Object;
    Queue *ptr;
    ptr = &Object;

    ptr->size = 8; // size of array is 8 therefore size of queue is also 8
    ptr->f = ptr->r = -1;
    ptr->arr = new int[ptr->size];
    // Enqueue few element
    cout << "Queue of size Eight:: (Enqueue four elements from front)" << endl;
    Object.enqueueFront(ptr, 7);
    Object.enqueueFront(ptr, 8);
    Object.enqueueFront(ptr, 11);
    Object.enqueueFront(ptr, 12);
    Object.dequeDisplay(ptr);

    cout << "Queue of size Eight:: (Enqueue four elements from rear (last))" << endl;
    Object.enqueueLast(ptr, 34);
    Object.enqueueLast(ptr, 40);
    Object.enqueueLast(ptr, 18);
    Object.enqueueLast(ptr, 29);
    Object.dequeDisplay(ptr);

    cout << endl
         << "Trying to enqueue 9th element but Queue is full" << endl;
    // Object.enqueueFront(ptr, 35);

    cout << endl;
    Object.dequeDisplay(ptr);
    cout << "Queue of size Eight:: (Dequeue three elements from front)" << endl;
    cout << "     Dequeue - element " << Object.dequeueFront(ptr) << endl;
    cout << "     Dequeue - element " << Object.dequeueFront(ptr) << endl;
    cout << "     Dequeue - element " << Object.dequeueFront(ptr) << endl
         << endl;
    Object.dequeDisplay(ptr);
    cout << "     Dequeue - element " << Object.dequeueFront(ptr) << endl
         << endl;
    Object.dequeDisplay(ptr);
    cout << "Queue of size Eight:: (Dequeue three elements from rear (last))" << endl;
    cout << "     Dequeue - element " << Object.dequeueLast(ptr) << endl;
    cout << "     Dequeue - element " << Object.dequeueLast(ptr) << endl;
    cout << "     Dequeue - element " << Object.dequeueLast(ptr) << endl
         << endl;
    Object.dequeDisplay(ptr);
    cout << "     Dequeue - element " << Object.dequeueLast(ptr) << endl
         << endl;
    cout << "Trying to dequeue 9th element but Queue is Empty" << endl
         << endl;
    cout << "     Return Dequeue - element " << Object.dequeueLast(ptr) << " Because queue is empty" << endl;

    return 0;
}

// DEqueue(Doubly Ended queue) for ice cream
//         ^^^^^^^^^^        5        4         3       2          1 ---->    @@@@@@@@@@
//         ^^^^^^^^^^  <---- 1        2         3       4          5          @@@@@@@@@@
//     O    |      |         O        O         O     ( O )        O           |      |      O
//   --|--  |      |       --|--    --|--     --|--   --|--      --|--         |      |    --|--
//     ^    |      |         ^        ^         ^       ^          ^           |      |      ^
//    / \   |      |        / \      / \       / \     ( )        / \          |      |     / \       
// ice cream              dequeue                                enqueue
//                          and                                    and
//                        enqueue                                dequeue
// seller           (Remove for queue)                       (Insert in queue)
//                  ( Deletion End )                         ( Insertion End )
//                  (Insert in queue)                        (Remove for queue)
//                  ( Insertion End )                         ( Deletion End )

// DEqueue
// ----> Insertion from rear and front both is possible
// ----> Deletion  from rear and front both is possible

// Queue
// ----> Insertion from rear  is possible
// ----> Deletion  from front is possible

// Two types of Dequeue
// 1. Restricted Input DEqueue --> Insertion from front is Not Allowed
// 2. Restricted Output DEqueue --> Deletion from rear is Not Allowed
