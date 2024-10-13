#include <iostream>
#include <cstring>
using namespace std;

class Stack
{

public:
    int size;
    int top;
    char *arr;
    int isEmpty(Stack *ptr);
    int isFull(Stack *ptr);
    void push(Stack *ptr, char value);
    char pop(Stack *ptr);
    int precedence(const char ch);
    int isOperator(const char ch);
    char *infixToPostfix(const char *infix, Stack *sp);
    int stackTop(Stack *sp);
    // Stack(){top=-1;}
};

int Stack::stackTop(Stack *sp)
{
    return sp->arr[sp->top];
}

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

void Stack::push(Stack *ptr, const char value)
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

char Stack::pop(Stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack Underflow" << endl;
        return -1;
    }
    else
    {
        const char value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int Stack::precedence(const char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }

    else if (ch == '+' || ch == '-')
    {
        return 2;
    }

    else
    {
        return 0;
    }
}

int Stack::isOperator(const char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char *Stack::infixToPostfix(const char *infix, Stack *sp)
{
    sp->size = 100;
    sp->top = -1;
    sp->arr = new char[sp->size];

    char *postfix = new char[strlen(infix) + 1];

    // Stack *sp=new Stack();

    int i = 0; // Track infix Traversal
    int j = 0; // Track postfix addition

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }

    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }

    postfix[j] = '\0';
    return postfix;
}

int main()
{

    Stack Object;
    Stack *ptr;
    ptr = &Object;

    // ptr->size = 100;
    // ptr->top = -1;
    // ptr->arr = new char[ptr->size];

    const char *Infix_exp = "x - y / z + k * d ";

    cout << "Infix   : operand   [operator]  operand  :: A + B   ,   A - B   ,  A * B  ,  A / B " << endl;
    cout << "Prefix  : [operator]  operand   operand  :: + A B   ,   - A B   ,  * A B  ,  / A B " << endl;
    cout << "Postfix : operand   operand   [operator] :: A B +   ,   A B -   ,  A B *  ,  A B /" << endl
         << endl;

    cout << "************************Infix to Postfix convertion************************ " << endl;
    cout << "Example-1 ::  " << endl;
    cout << "********Infix Experssion :: x - y * z " << endl;
    cout << "STEP 1:: parathesize the experssion ::( x - ( y * z ) ) <---- start with inner most parenthesis" << endl;
    cout << "===> ( x - [ y z * ] ) " << endl;
    cout << "===> [ x [ y z * ] - ]" << endl;
    cout << "********Postfix Experssion::  x y z * -  " << endl
         << endl;
    cout << "Example-2 ::  " << endl;
    cout << "********Infix Experssion :: x - y / z + k * d " << endl;
    cout << "STEP 1:: parathesize the experssion ::( ( x - ( y / z ) ) + ( k * d ) ) <---- start with inner most parenthesis " << endl;
    cout << "===> ( ( x - [ y z / ] ) + [ k  d *] ) " << endl;
    cout << "===> ( [ x [ y z / ] - ] + [ k  d *] ) " << endl;
    cout << "===> [ [ x [ y z / ] - ]  [ k  d *] + ] " << endl;
    cout << "********Postfix Experssion ::  x y z / - k d * + " << endl
         << endl;

    cout << "*****************Implementation of Stack for Infix to postfix convertion***************** " << endl;
    cout << "********Infix Experssion :: x - y / z + k * d " << endl;
    cout << "                            ^" << endl;
    cout << "                            |" << endl
         << endl;
    cout << "********Postfix Experssion :: x " << endl
         << endl;

    cout << "        |            |" << endl;
    cout << "        |            |" << endl;
    cout << "        |            |" << endl;
    cout << "        --------------" << endl;

    cout << "********Infix Experssion :: x - y / z + k * d " << endl;
    cout << "                              ^" << endl;
    cout << "                              |" << endl;
    cout << "                             push " << endl;

    cout << "        |            |" << endl;
    cout << "        |            |" << endl;
    cout << "        |      -     |" << endl;
    cout << "        --------------" << endl;

    cout << "********Postfix Experssion :: x " << endl
         << endl;

    cout << "********Infix Experssion :: x - y / z + k * d " << endl;
    cout << "                                ^" << endl;
    cout << "                                |" << endl
         << endl;
    cout << "********Postfix Experssion :: x y" << endl
         << endl;

    cout << "********Infix Experssion :: x - y / z + k * d " << endl;
    cout << "                                  ^" << endl;
    cout << "                                  |" << endl;
    cout << "                                 push " << endl;

    cout << "        |            |" << endl;
    cout << "        |      /     |" << endl;
    cout << "        |      -     |" << endl;
    cout << "        --------------" << endl;

    cout << "********Postfix Experssion :: x y" << endl
         << endl;

    cout << "********Infix Experssion :: x - y / z + k * d " << endl;
    cout << "                                    ^" << endl;
    cout << "                                    |" << endl
         << endl;

    cout << "********Postfix Experssion :: x y z " << endl
         << endl;

    cout << "********Infix Experssion :: x - y / z + k * d " << endl;
    cout << "                                      ^" << endl;
    cout << "                                      |" << endl;
    cout << "      check operator precedence pop stack  " << endl;

    cout << "        |            |" << endl;
    cout << "        |            |" << endl;
    cout << "        |      -     |" << endl;
    cout << "        --------------" << endl;

    cout << "********Postfix Experssion :: x y z / " << endl
         << endl;

    cout << "********Infix Experssion :: x - y / z + k * d " << endl;
    cout << "                                      ^" << endl;
    cout << "                                      |" << endl;
    cout << "      check operator precedence pop stack  " << endl;

    cout << "        |            |" << endl;
    cout << "        |            |" << endl;
    cout << "        |            |" << endl;
    cout << "        --------------" << endl;

    cout << "********Postfix Experssion :: x y z / - " << endl
         << endl;

    cout << "********Infix Experssion :: x - y / z + k * d " << endl;
    cout << "                                      ^" << endl;
    cout << "                                      |" << endl;
    cout << "                                     push " << endl;

    cout << "        |            |" << endl;
    cout << "        |            |" << endl;
    cout << "        |      +     |" << endl;
    cout << "        --------------" << endl;

    cout << "********Postfix Experssion :: x y z / - " << endl
         << endl;

    cout << "********Infix Experssion :: x - y / z + k * d " << endl;
    cout << "                                        ^" << endl;
    cout << "                                        |" << endl
         << endl;
    cout << "********Postfix Experssion :: x y z / - k" << endl
         << endl;

    cout << "********Infix Experssion :: x - y / z + k * d " << endl;
    cout << "                                          ^" << endl;
    cout << "                                          |" << endl;
    cout << "                                         push " << endl;

    cout << "        |            |" << endl;
    cout << "        |      *     |" << endl;
    cout << "        |      +     |" << endl;
    cout << "        --------------" << endl;
    cout << "********Postfix Experssion :: x y z / - k" << endl
         << endl;

    cout << "********Infix Experssion :: x - y / z - k * d " << endl;
    cout << "                                            ^" << endl;
    cout << "                                            |" << endl
         << endl;
    cout << "********Postfix Experssion :: x y z / - k d " << endl
         << endl;

    cout << "Now experssion is over pop all the element of stack " << endl;
    cout << "********Postfix Experssion :: x y z / - k d * " << endl
         << endl;

    cout << "        |            |" << endl;
    cout << "        |            |" << endl;
    cout << "        |      +     |" << endl;
    cout << "        --------------" << endl;
    cout << "********Postfix Experssion :: x y z / - k d * +       <----- final experssion after convertion " << endl
         << endl;

    cout << "        |            |" << endl;
    cout << "        |            |" << endl;
    cout << "        |            |" << endl;
    cout << "        --------------" << endl;

    cout << "Infix Experssion :: " << Infix_exp << endl;
    cout << "After convertion from Infix Expression to Postfix Experssion" << endl;

    cout << "Postfix Experssion :: " << Object.infixToPostfix(Infix_exp, ptr) << endl;

    return 0;
}