#include <iostream>
using namespace std;

class Queue
{
public:
    int size;
    int f;
    int r;
    int *arr;
    void enqueue(Queue *q, int value);
    int isFull(Queue *q);
    int isEmpty(Queue *q);
    int dequeue(Queue *q);
};

int Queue::isFull(Queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

int Queue::isEmpty(Queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

void Queue::enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        cout << "This Queue is Full" << endl;
    }
    else
    {
        q->r++;
        q->arr[q->r] = value;
    }
}

int Queue::dequeue(Queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        cout << "This Queue is Empty" << endl;
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    cout << "***************Queue using Array***************" << endl;
    Queue Object;
    Queue *ptr;
    ptr = &Object;

    ptr->size = 4; // size of array is 4 therefore size of queue is also 4
    ptr->f = ptr->r = -1;
    ptr->arr = new int[ptr->size];
    // Enqueue few element
    cout << "Queue of size four:: (Enqueue four elements)" << endl;
    Object.enqueue(ptr, 7);
    Object.enqueue(ptr, 8);
    Object.enqueue(ptr, 11);
    Object.enqueue(ptr, 12);

    for (int i = ptr->f + 1; i <= ptr->r; i++)
    {
        cout << "     Element " << (i + 1) << " of Queue :: " << ptr->arr[i] << endl;
    }
    cout << endl
         << "Trying to enqueue 5th element but Queue is full" << endl;
    Object.enqueue(ptr, 35);

    cout << endl
         << "Queue of size four:: (Dequeue three elements)" << endl;
    cout << "     Dequeue - element " << Object.dequeue(ptr) << endl;
    cout << "     Dequeue - element " << Object.dequeue(ptr) << endl;
    cout << "     Dequeue - element " << Object.dequeue(ptr) << endl
         << endl;

    for (int i = ptr->f + 1; i <= ptr->r; i++)
    {
        cout << "     Element " << (i + 1) << " of Queue :: " << ptr->arr[i] << endl;
    }
    cout << "     Dequeue - element " << Object.dequeue(ptr) << endl
         << endl;
    cout << "Trying to dequeue 5th element but Queue is Empty" << endl
         << endl;
    cout << "     Return Dequeue - element " << Object.dequeue(ptr) << " Because queue is empty" << endl;

    return 0;
}

// QUEUE for ice cream (FIFO::first come first serves )
//
//         ^^^^^^^^^^     1        2         3       4          5
//     O    |      |      O        O         O     ( O )        O
//   --|--  |      |    --|--    --|--     --|--   --|--      --|--
//     ^    |      |      ^        ^         ^       ^          ^
//    / \   |      |     / \      / \       / \     ( )        / \
// ice cream            dequeue                               enqueue
// seller           (Remove for queue)                       (Insert in queue)
//                  ( Deletion End )                         ( Insertion End )

// Queue using Array

// Inserting element Incrementing r and inserting value in array

// Array Before
// index--->  -1  0  1   2   3
// value--->   |
// front,rear: f,r

// index--->  -1  0  1   2   3
// value--->      7
// front,rear:  f  r

// index--->  -1  0  1   2   3
// value--->      7  8
// front,rear: f      r

// index--->  -1  0  1   2   3
// value--->      7  8  11
// front,rear: f          r

// Array After
// index--->  -1  0  1   2   3
// value--->      7  8  11  12
// front,rear:  f             r <---- Queue is Full

// Deleting element Incrementing f and remove element at f

// Array Before
// index--->  -1  0  1   2   3
// value--->      7  8  11  12
// front,rear:  f             r

// Array After
// index--->  -1  0  1   2   3
// value--->         8  11  12
// front,rear:     f          r

// index--->  -1  0  1   2   3
// value--->             11  12
// front,rear:        f       r

// index--->  -1  0  1   2   3
// value--->                 12
// front,rear:            f    r

// index--->  -1  0  1   2   3
// value--->
// front,rear:                f,r <---- Queue is Empty