#include <iostream>
using namespace std;

class circularQueue
{
public:
    int size;
    int f;
    int r;
    int *arr;
    void enqueue(circularQueue *q, int value);
    int isFull(circularQueue *q);
    int isEmpty(circularQueue *q);
    int dequeue(circularQueue *q);
};

int circularQueue::isFull(circularQueue *q)
{
    if ((q->r+1)%q->size== q->f)
    {
        return 1;
    }
    return 0;
}

int circularQueue::isEmpty(circularQueue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

void circularQueue::enqueue(circularQueue *q, int value)
{
    if (isFull(q))
    {
        cout << "This Queue is Full" << endl;
    }
    else
    {
        q->r=(q->r+1)%q->size;
        q->arr[q->r] = value;
    }
}

int circularQueue::dequeue(circularQueue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        cout << "This Queue is Empty" << endl;
    }
    else
    {
        q->f=(q->f+1)%q->size;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    cout << "***************Circular Queue using Array***************" << endl;
    cout<<"Drawback of Queue using Arrays::: Space is Not used efficiently , Space get wasted"<<endl;
    cout<<"Circular Queue:: There is No waste of Space element"<<endl<<endl;
    circularQueue Object;
    circularQueue *ptr;
    ptr = &Object;

    ptr->size = 4; // size of array is 4 therefore size of queue is also 4
    ptr->f = ptr->r = 0;
    ptr->arr = new int[ptr->size];
    // Enqueue few element
    cout << "Queue of size four:: (Enqueue three elements , NOTE:: Queue of size four can enqueue only three elements )" << endl;
    Object.enqueue(ptr, 7);
    Object.enqueue(ptr, 8);
    Object.enqueue(ptr, 11);

    for (int i = ptr->f + 1; i <= ptr->r; i++)
    {
        cout << "     Element " << i  << " of Queue :: " << ptr->arr[i] << endl;
    }
    cout << endl
         << "Trying to enqueue 4th and 5th element but Queue is full" << endl;
    Object.enqueue(ptr, 12);
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
    cout << "Trying to dequeue 4th and 5th element but Queue is Empty" << endl
         << endl;
    cout << "     Return Dequeue - element " << Object.dequeue(ptr) << " Because queue is empty" << endl;
    cout << "     Dequeue - element " << Object.dequeue(ptr) << endl
         << endl;

    return 0;
}

// //  Circular Queue is Empty Now (Now Enqueue)        |    Circular Queue is Empty Now (NO Dequeue is possible )
//                                                      |
//              0    1    2                             |                            0    1    2                             |             
// f,r  /----|----|----|----|-----\                     |               f,r  /----|----|----|----|-----\                     |
// |-->/  X  |    |    |    |      \   3                |               |-->/  X  | X  | X  | X  | X    \   3                |
// 9  /  X  /|----|----|----|\      \                   |               9  /  X  /|----|----|----|\ X    \                   |
//   /  X  /                  \      \                  |                 /  X  /                  \  X   \                  |
//  (-----(                    )------)                 |                (-----(                    )------)                 |
//   \     \                  /      /                  |                 \  X  \                  /   X  /                  |
//    \     \|----|----|----|/      /                   |                  \  X  \|----|----|----|/  X   /                   |
//  8  \     |    |    |    |      /  4                 |                8  \   X | X  | X  | X  | X    /  4                 |
//      \----|----|----|----|-----/                     |                    \----|----|----|----|-----/                     |
//             7     6    5                             |                           7     6    5                             |
//                                                      |
//                                                      |
//                                                      | 
//       r-----|                                        |                     f-----|                                        |
//             0    1    2                              |                           0    1    2                              |
// f    /----|----|----|----|-----\                     |               r    /----|----|----|----|-----\                     |
// |-->/  X  |  7 |    |    |      \   3                |               |-->/  X  |  X |  X | X  |   X  \   3                |
// 9  /  X  /|----|----|----|\      \                   |               9  /  X  /|----|----|----|\   X  \                   |
//   /  X  /                  \      \                  |                 /  X  /                  \   X  \                  |
//  (-----(                    )------)                 |                (-----(                    )------)                 |
//   \     \                  /      /                  |                 \  X  \                  /  X   /                  |
//    \     \|----|----|----|/      /                   |                  \  X  \|----|----|----|/  X   /                   |
//  8  \     |    |    |    |      /  4                 |                8  \  X  | X  | X  | X  |  X   /  4                 |
//      \----|----|----|----|-----/                     |                    \----|----|----|----|-----/                     |
//             7     6    5                             |                           7     6    5                             |
//                                                      |
//                                                      |
//                                                      |
//            r-----|                                   |                         f-----|                                   |
//             0    1    2                              |                          0    1    2                              |
// f    /----|----|----|----|-----\                     |              r    /----|----|----|----|-----\                     |
// |-->/  X  |  7 | 11 |    |      \   3                |              |-->/  X  |  7 |  X | X  |   X  \   3                |
// 9  /  X  /|----|----|----|\      \                   |              9  /  X  /|----|----|----|\   X  \                   |
//   /  X  /                  \      \                  |                /  X  /                  \   X  \                  |
//  (-----(                    )------)                 |               (-----(                    )------)                 |
//   \     \                  /      /                  |                \ X   \                  /   X  /                  |
//    \     \|----|----|----|/      /                   |                 \ X   \|----|----|----|/  X   /                   |
//  8  \     |    |    |    |      /  4                 |               8  \ X   | X  | X  | X  | X    /  4                 |
//      \----|----|----|----|-----/                     |                   \----|----|----|----|-----/                     |
//             7     6    5                             |                          7     6    5                             |
//                                                      |
//                                                      |
//                 r-----|                              |                            f-----|                              |
//             0    1    2                              |                        0    1    2                              |
// f    /----|----|----|----|-----\                     |            r    /----|----|----|----|-----\                     |
// |-->/  X  |  7 | 11 | 12 |      \   3                |            |-->/ X   |  7 | 11 |  X |   X  \   3                |
// 9  /  X  /|----|----|----|\      \                   |            9  / X   /|----|----|----|\   X  \                   |
//   /  X  /                  \      \                  |              / X   /                  \   X  \                  |
//  (-----(                    )------)                 |             (-----(                    )------)                 |
//   \     \                  /      /                  |              \  X  \                  /   X  /                  |
//    \     \|----|----|----|/      /                   |               \  X  \|----|----|----|/  X   /                   |
//  8  \     |    |    |    |      /  4                 |             8  \  X  | X  | X  | X  | X    /  4                 |
//      \----|----|----|----|-----/                     |                 \----|----|----|----|-----/                     |
//             7     6    5                             |                        7     6    5                             |
//                                                      |
//                                                      |
//                                                      |
//                                                      | 
//             0    1    2                              |                       0    1    2                              |     
// f    /----|----|----|----|-----\                     |           r    /----|----|----|----|-----\                     |
// |-->/  X  |  7 | 11 | 12 |      \   3<----r          |           |-->/ X   |  7 | 11 | 12 |  X   \   3<----f          |
// 9  /  X  /|----|----|----|\   8  \                   |           9  / X   /|----|----|----|\   X  \                   |
//   /  X  /                  \      \                  |             / X   /                  \   X  \                  |
//  (-----(                    )------)                 |            (-----(                    )------)                 |
//   \     \                  /      /                  |             \  X  \                  /    X /                  |
//    \     \|----|----|----|/      /                   |              \  X  \|----|----|----|/   X  /                   |
//  8  \     |    |    |    |      /  4                 |            8  \  X  | X  | X  | X  |  X   /  4                 |
//      \----|----|----|----|-----/                     |                \----|----|----|----|-----/                     |
//             7     6    5                             |                       7     6    5                             |
//                                                      |
//                                                      |
//                                                      | 
//                                                      |   
//             0    1    2                              |                      0    1    2                               |        
// f    /----|----|----|----|-----\                     |           r    /----|----|----|----|-----\                     |
// |-->/  X  |  7 | 11 | 12 |      \   3                |           |-->/  X  |  7 | 11 | 12 |      \   3                |
// 9  /  X  /|----|----|----|\   8  \                   |           9  / X   /|----|----|----|\   8  \                   |
//   /  X  /                  \      \                  |             / X   /                  \      \                  |
//  (-----(                    )------)                 |            (-----(                    )------)                 |
//   \     \                  /      /                  |             \  X  \                  /   X  /                  |
//    \     \|----|----|----|/  26  /                   |              \  X  \|----|----|----|/   X  /                   |
//  8  \     |    |    |    |      /  4<----r           |            8  \  X  |  X |  X | X  |   X  /  4<----f           |
//      \----|----|----|----|-----/                     |                \----|----|----|----|-----/                     |
//             7     6    5                             |                       7     6    5                             |
//                                                      |
//                                                      |
//                                                      |
//                                                      |
//             0    1    2                              |                        0    1    2                              |     
// f    /----|----|----|----|-----\                     |            r    /----|----|----|----|-----\                     |
// |-->/  X  |  7 | 11 | 12 |      \   3                |            |-->/  X  |  7 | 11 | 12 |      \   3                |
// 9  /  X  /|----|----|----|\  8   \                   |            9  /  X  /|----|----|----|\  8   \                   |
//   /  X  /                  \      \                  |              /  X  /                  \      \                  |
//  (-----(                    )------)                 |             (-----(                    )------)                 |
//   \     \                  /      /                  |              \  X  \                  /      /                  |  
//    \     \|----|----|----|/  26  /                   |               \  X  \|----|----|----|/  26  /                   |
//  8  \     |    |    |  2 |      /  4                 |             8  \  X  | X  |  X |  X |      /  4                 |
//      \----|----|----|----|-----/                     |                 \----|----|----|----|-----/                     |
//             7     6    5                             |                        7     6    5                             |
//                        |-----r                       |                                   |-----f                       |
//                                                      |
//                                                      |
//                                                      |
//             0    1    2                              |                       0    1    2                              |     
// f    /----|----|----|----|-----\                     |           r    /----|----|----|----|-----\                     |
// |-->/  X  |  7 | 11 | 12 |      \   3                |           |-->/ X   |  7 | 11 | 12 |      \   3                |
// 9  /  X  /|----|----|----|\  8   \                   |           9  / X   /|----|----|----|\  8   \                   |
//   /  X  /                  \      \                  |             / X   /                  \      \                  |
//  (-----(                    )------)                 |            (-----(                    )------)                 |
//   \     \                  /      /                  |             \  X  \                  /      /                  |
//    \     \|----|----|----|/  26  /                   |              \  X  \|----|----|----|/  26  /                   |
//  8  \     |    |  5 |  2 |      /  4                 |            8  \  X  |  X |  X |  2 |      /  4                 |
//      \----|----|----|----|-----/                     |                \----|----|----|----|-----/                     |
//             7     6    5                             |                       7     6    5                             |
//                   |-----r                            |                             |-----f                            |
//                                                      |
//                                                      |
//                                                      | 
//                                                      | 
//             0    1    2                              |                       0    1    2                              |       
// f    /----|----|----|----|-----\                     |           r    /----|----|----|----|-----\                     |
// |-->/  X  |  7 | 11 | 12 |      \   3                |           |-->/ X   |  7 | 11 | 12 |      \   3                |
// 9  /  X  /|----|----|----|\  8   \                   |           9  / X   /|----|----|----|\  8   \                   |
//   /  X  /                  \      \                  |             / X   /                  \      \                  |
//  (-----(                    )------)                 |            (-----(                    )------)                 |
//   \     \                  /      /                  |             \  X  \                  /      /                  |
//    \     \|----|----|----|/  26  /                   |              \  X  \|----|----|----|/  26  /                   |
//  8  \     | 18 |  5 |  2 |      /  4                 |            8  \  X  | X  |  5 |  2 |      /  4                 |
//      \----|----|----|----|-----/                     |                \----|----|----|----|-----/                     |
//             7     6    5                             |                       7     6    5                             |  
//             |-----r                                  |                       |-----f                                  |
//                                                      |
//                                                      |
//                                                      |
//                                                      |
//             0    1    2                              |                        0    1    2                              |     
// f    /----|----|----|----|-----\                     |            r    /----|----|----|----|-----\                     |
// |-->/  X  |  7 | 11 | 12 |      \   3                |            |-->/  X  |  7 | 11 | 12 |      \   3                |
// 9  /  X  /|----|----|----|\  8   \                   |            9  /  X  /|----|----|----|\  8   \                   |
//   /  X  /                  \      \                  |              /  X  /                  \      \                  |               
//  (-----(                    )------)                 |             (-----(                    )------)                 |
//   \     \                  /      /                  |              \  X  \                  /      /                  |
//    \  15 \|----|----|----|/  26  /                   |               \  X  \|----|----|----|/  26  /                   |
//  8  \     | 18 |  5 |  2 |      /  4                 |             8  \  X  | 18 |  5 |  2 |      /  4                 |
//  ^   \----|----|----|----|-----/                     |             ^   \----|----|----|----|-----/                     |
//  |          7     6    5                             |             |          7     6    5                             |
//  |-----r                                             |             |-----f                                             |
//                                                      |                                                      |
//                                                      |
//             0    1    2                              |                        0    1    2                              |
// f,r  /----|----|----|----|-----\                     |           f,r   /----|----|----|----|-----\                     | 
// |-->/  X  |  7 | 11 | 12 |      \   3                |            |-->/ X   |  7 | 11 | 12 |      \   3                |
// 9  / X   /|----|----|----|\  8   \                   |            9  / X   /|----|----|----|\  8   \                   |
//   / X   /                  \      \                  |              / X   /                  \      \                  |
//  (-----(                    )------)                 |             (-----(                    )------)                 |
//   \     \                  /      /                  |              \     \                  /      /                  |
//    \  15 \|----|----|----|/  26  /                   |               \  15 \|----|----|----|/  26  /                   |
//  8  \     | 18 |  5 |  2 |      /  4                 |             8  \     | 18 |  5 |  2 |      /  4                 |
//      \----|----|----|----|-----/                     |                 \----|----|----|----|-----/                     |
//             7     6    5                             |                        7     6    5                             |
//                                                      |                                                                 |
//  Circular Queue is Full Now (NO Enqueue is possible )|//  Circular Queue is Full Now (Now Dequeue  )|              
//                                                      |
