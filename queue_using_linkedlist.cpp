#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *f = NULL;
    Node *r = NULL;
    void enqueue(int value);
    void linkedlistTraversal(Node *ptr);
    int dequeue();
};

void Node::enqueue(int value)
{
    Node *n = new Node();
    if (n == NULL)
    {
        cout << "Queue is Full" << endl;
    }
    else
    {

        if (f == NULL)
        {
            f = r = n;
        }

        n->data = value;
        n->next = NULL;
        r->next = n;
        r = n;
    }
}

void Node::linkedlistTraversal(Node *ptr)
{
    cout << endl
         << "*******Printing the element of this Linkedlist*******" << endl;
    int i = 0;
    while (ptr != NULL)
    {
        i++;
        cout << "Element " << i << "::  " << ptr->data << endl;
        ptr = ptr->next;
    }
}

int Node::dequeue()
{
    int value = -1;
    Node *ptr = f;
    if (f == NULL)
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        f = f->next;
        value = ptr->data;
        delete ptr;
    }
    return value;
}

int main()
{
    cout << "**************Queue Using Linkedlist**************" << endl;
    Node Object;
    cout << endl
         << "Enqueue few elements in the Queue " << endl;
    Object.enqueue(14);
    Object.enqueue(24);
    Object.enqueue(37);
    Object.enqueue(44);
    Object.enqueue(54);
    Object.enqueue(67);
    Object.linkedlistTraversal(Object.f);
    cout << endl
         << "Dequeue few elements in the Queue " << endl;
    cout << "Dequeue Element 1::  " << Object.dequeue() << endl;
    cout << "Dequeue Element 1::  " << Object.dequeue() << endl;
    cout << "Dequeue Element 1::  " << Object.dequeue() << endl;
    Object.linkedlistTraversal(Object.f);
    return 0;
}



// In Linkedlist we are Implementing Queue by Insertion at end node of Linkedlist , Deletion at (Head) first node of Linkedlist