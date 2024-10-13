#include <iostream>
using namespace std;

class Stack
{

public:
    int size;
    int top;
    int *arr;
    int isEmpty(Stack *ptr);
    int isFull(Stack *ptr);
    void push(Stack *ptr, int value);
    int pop(Stack *ptr);
    int peek(Stack *ptr, int i);

    // Stack(){top=-1;}
};

int Stack::isEmpty(Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Stack::isFull(Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Stack::push(Stack *ptr, int value)
{
    if (isFull(ptr))
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int Stack::pop(Stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack Underflow" << endl;
        return -1;
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int Stack::peek(Stack *ptr, int i)
{
    int arrayInd = ptr->top - i + 1;
    if (ptr->top - i + 1 < 0)
    {
        cout << "Not vaild position for the stack" << endl;
        return -1;
    }
    else
    {
        return ptr->arr[arrayInd];
    }
}

int main()
{
    cout << "**************Stack creation and operation of stack*************" << endl;
    cout << "pop()----->Top most element is removed from stack  (deletion)" << endl;
    cout << "push()----->Top most element is inserted in stack   (insertion)" << endl;
    cout << "peek()----->element position index  (searching)" << endl
         << endl;

    cout << "Stack has been created sucessfully of size 5" << endl;
    Stack Object;
    Stack *ptr;
    ptr = &Object;

    ptr->size = 5;
    ptr->top = -1;
    ptr->arr = new int[ptr->size];

    cout << "*****Before Pushing element in stack is Empty*****" << endl
         << endl;

    cout << "        |            |" << endl;
    cout << "        --------------" << endl
         << endl;
    Object.push(ptr, 56);
    Object.push(ptr, 46);
    Object.push(ptr, 36);

    cout << "*****After Pushing 3 element in stack***** " << endl;

    cout << "TOP---->|    " << Object.peek(ptr, 1) << "      |" << endl;
    cout << "        |            |" << endl;
    cout << "        --------------" << endl;
    for (int i = 2; i <= ptr->top + 1; i++)
    {
        cout << "        |    " << Object.peek(ptr, i) << "      |" << endl;
        cout << "        |            |" << endl;
        cout << "        --------------" << endl;
    }

    cout << "*****After Pushing 5 element stack is Full***** " << endl
         << endl;

    Object.push(ptr, 26);
    Object.push(ptr, 16);

    cout << "TOP---->|    " << Object.peek(ptr, 1) << "      |" << endl;
    cout << "        |            |" << endl;
    cout << "        --------------" << endl;
    for (int i = 2; i <= ptr->top + 1; i++)
    {
        cout << "        |    " << Object.peek(ptr, i) << "      |" << endl;
        cout << "        |            |" << endl;
        cout << "        --------------" << endl;
    }

    cout << "*****Before Popped element in stack is Full*****" << endl
         << endl;

    cout << "TOP---->|    " << Object.peek(ptr, 1) << "      |" << endl;
    cout << "        |            |" << endl;
    cout << "        --------------" << endl;
    for (int i = 2; i <= ptr->top + 1; i++)
    {
        cout << "        |    " << Object.peek(ptr, i) << "      |" << endl;
        cout << "        |            |" << endl;
        cout << "        --------------" << endl;
    }

    cout << "Popped " << Object.pop(ptr) << " from the stack" << endl;
    cout << "Popped " << Object.pop(ptr) << " from the stack" << endl;
    cout << "Popped " << Object.pop(ptr) << " from the stack" << endl;

    cout << "*****After Popped 3 element in stack***** " << endl;

    cout << "TOP---->|    " << Object.peek(ptr, 1) << "      |" << endl;
    cout << "        |            |" << endl;
    cout << "        --------------" << endl;
    for (int i = 2; i <= ptr->top + 1; i++)
    {
        cout << "        |    " << Object.peek(ptr, i) << "      |" << endl;
        cout << "        |            |" << endl;
        cout << "        --------------" << endl;
    }

    cout << "Popped " << Object.pop(ptr) << " from the stack" << endl;
    cout << "Popped " << Object.pop(ptr) << " from the stack" << endl;

    cout << "*****After Popped 5 element in stack is Empty***** " << endl
         << endl;
    cout << "        |            |" << endl;
    cout << "        --------------" << endl
         << endl;

    Object.push(ptr, 56);
    Object.push(ptr, 46);
    Object.push(ptr, 36);
    Object.push(ptr, 26);
    Object.push(ptr, 16);

    cout << "***** Peek opration *****" << endl;
    for (int i = 1; i <= ptr->top + 1; i++)
    {
        cout << "the value at position " << i << " is " << Object.peek(ptr, i) << endl
             << endl;
    }

    cout << "TOP---->|    " << Object.peek(ptr, 1) << "      |" << endl;
    cout << "        |            |" << endl;
    cout << "        --------------" << endl;
    for (int i = 2; i <= ptr->top + 1; i++)
    {
        cout << "        |    " << Object.peek(ptr, i) << "      |" << endl;
        cout << "        |            |" << endl;
        cout << "        --------------" << endl;
    }

    cout << "NOTE:: Time Complexity of stack operations is O(1) for push() , pop() , peek()" << endl;
    cout << "peek() is to show potion of element on Top " << endl;

    return 0;
}