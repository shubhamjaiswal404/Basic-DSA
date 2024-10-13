#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

class Stack
{
public:
    static int count;
    Node *top = NULL; // Global variable

    int isEmpty(Node *top);
    int isFull(Node *top);
    Node *push(Node *top, int x);
    void linkedListTraversal(Node *ptr);
    int pop(Node **top);
    // int pop (Node* top);// it will give error
    int peek(int pos);
};

int Stack::isEmpty(Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Stack::isFull(Node *top)
{
    Node *p = new Node();
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

Node *Stack::push(Node *top, int x)
{
    cout << "Count after pushing element in the stack : " << count++ << endl;
    if (isFull(top))
    {
        cout << "Stack overflow" << endl;
    }
    else
    {
        Node *n = new Node();
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

void Stack::linkedListTraversal(Node *ptr)
{
    cout << "**********Linkedlist traversal*************" << endl;
    while (ptr != NULL)
    {
        cout << "Element : " << ptr->data << endl;
        ptr = ptr->next;
    }
}

int Stack::pop(Node **top)
{
    cout << "Count after poping element in the stack : " << --count << endl;
    if (isEmpty(*top))
    {
        cout << "stack underflow" << endl;
    }
    else
    {
        Node *n = *top;
        *top = (*top)->next;
        int x = n->data;
        delete n;
        return x;
    }
}

// Error Because we have to give address of top to the function
// int Stack::pop (Node* tp){
//     if(isEmpty(tp)){
//         cout<<"stack underflow"<<endl;
//         return -1;
//     }
//     else{
//         Node* n = tp;
//         tp = tp->next;
//         int x =n->data;
//         delete n;
//         return x;
//     }

// }

int Stack::peek(int pos)
{
    Node *ptr = top;
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}

int Stack::count = 1;

int main()
{
    cout << "**************Stack creation  using Linkedlist and operation of stack*************" << endl;

    cout << "Stack has been created sucessfully of size 5" << endl;

    cout << "*****Before Pushing element in stack is Empty*****" << endl
         << endl;

    cout << "        |            |" << endl;
    cout << "        --------------" << endl
         << endl;

    Stack Object;
    Object.top = Object.push(Object.top, 56);
    Object.top = Object.push(Object.top, 46);
    Object.top = Object.push(Object.top, 36);
    Object.linkedListTraversal(Object.top);

    // cout<<"count : "<<Stack::count<<endl;

    cout << "*****After Pushing 3 element in stack***** " << endl;

    cout << "TOP---->|    " << Object.peek(1) << "      |" << endl;
    cout << "        |            |" << endl;
    cout << "        --------------" << endl;
    for (int i = 2; i < Stack::count; i++)
    {
        cout << "        |    " << Object.peek(i) << "      |" << endl;
        cout << "        |            |" << endl;
        cout << "        --------------" << endl;
    }

    Object.top = Object.push(Object.top, 26);
    Object.top = Object.push(Object.top, 16);
    Object.linkedListTraversal(Object.top);

    cout << "*****After Pushing 5 element stack is Full***** " << endl
         << endl;

    cout << "TOP---->|    " << Object.peek(1) << "      |" << endl;
    cout << "        |            |" << endl;
    cout << "        --------------" << endl;
    for (int i = 2; i < Stack::count; i++)
    {
        cout << "        |    " << Object.peek(i) << "      |" << endl;
        cout << "        |            |" << endl;
        cout << "        --------------" << endl;
    }

    cout << "*****Before Popped element in stack is Full*****" << endl
         << endl;

    cout << "TOP---->|    " << Object.peek(1) << "      |" << endl;
    cout << "        |            |" << endl;
    cout << "        --------------" << endl;
    for (int i = 2; i < Stack::count; i++)
    {
        cout << "        |    " << Object.peek(i) << "      |" << endl;
        cout << "        |            |" << endl;
        cout << "        --------------" << endl;
    }

    int element1 = Object.pop(&Object.top);
    cout << "Popped element is " << element1 << endl;

    int element2 = Object.pop(&Object.top);
    cout << "Popped element is " << element2 << endl;

    int element3 = Object.pop(&Object.top);
    cout << "Popped element is " << element3 << endl;

    Object.linkedListTraversal(Object.top);

    cout << "*****After Popped 3 element in stack***** " << endl;

    cout << "TOP---->|    " << Object.peek(1) << "      |" << endl;
    cout << "        |            |" << endl;
    cout << "        --------------" << endl;
    for (int i = 2; i < Stack::count; i++)
    {
        cout << "        |    " << Object.peek(i) << "      |" << endl;
        cout << "        |            |" << endl;
        cout << "        --------------" << endl;
    }

    int element4 = Object.pop(&Object.top);
    cout << "Popped element is " << element4 << endl;

    int element5 = Object.pop(&Object.top);
    cout << "Popped element is " << element5 << endl;

    Object.linkedListTraversal(Object.top);

    cout << "*****After Popped 5 element in stack is Empty***** " << endl
         << endl;
    cout << "        |            |" << endl;
    cout << "        --------------" << endl
         << endl;

    cout << "***** Peek opration to show elements in stack *****" << endl;
    Object.top = Object.push(Object.top, 56);
    Object.top = Object.push(Object.top, 46);
    Object.top = Object.push(Object.top, 36);
    Object.top = Object.push(Object.top, 26);
    Object.top = Object.push(Object.top, 16);

    Object.linkedListTraversal(Object.top);

    cout << "***** Peek opration *****" << endl;
    for (int i = 1; i < Stack::count; i++)
    {
        cout << "the value at position " << i << " is " << Object.peek(i) << endl
             << endl;
    }

    cout << "TOP---->|    " << Object.peek(1) << "      |" << endl;
    cout << "        |            |" << endl;
    cout << "        --------------" << endl;

    for (int i = 2; i < Stack::count; i++)
    {
        cout << "        |    " << Object.peek(i) << "      |" << endl;
        cout << "        |            |" << endl;
        cout << "        --------------" << endl;
    }

    for (int i = 1; i <= 4; i++)
    {
        cout << "value at position " << i << " is : " << Object.peek(i) << endl;
    }

    cout << "NOTE:: Time Complexity of stack operations is O(1) for push() , pop() , peek()" << endl;
    cout << "peek() is to show potion of element on Top " << endl;

    return 0;
}