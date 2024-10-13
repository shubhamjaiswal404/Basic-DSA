#include <iostream>
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
    int paraenthesisMatching(const char *exp, Stack *sp);
    int match(char a, char b);
    char stackTop(Stack *sp);

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

int Stack ::paraenthesisMatching(const char *exp, Stack *sp)
{

    sp->size = 100;
    sp->top = -1;
    sp->arr = new char[sp->size];

    char popped_ch;
    int count = 0;
    int count2 = 0;

    // Creation and initialization the stack
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            count2++;
            push(sp, exp[i]);
            cout << "  PUSH---> |     " << exp[i] << "      |<------ same " << count2 << endl;
            cout << "           |            |" << endl;
            cout << "           --------------" << endl;
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                cout << "******Stack Underflow******" << endl;
                cout << "   POP---> |     " << exp[i] << "      | <------ Not possible because Stack is empty" << endl;
                cout << "           |            |" << endl;
                cout << "           --------------" << endl;
                return 0;
            }
            if ((match(stackTop(sp), exp[i])))
            {
                cout << "PUSH == POP  " << endl;
            }
            else
            {
                cout << "PUSH != POP <----- pop operation is not possible " << endl;
            }
            if (match(stackTop(sp), exp[i]))
            {

                popped_ch = pop(sp);
                cout << "   POP---> |     " << exp[i] << "      |<------ same " << count2 << endl;
                cout << "           |            |" << endl;
                cout << "           --------------" << endl;
                count2--;
            }
            else
            {
                return 0;
            }
        }
    }

    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char Stack::stackTop(Stack *sp)
{

    return sp->arr[sp->top];
}

int Stack::match(char a, char b)
{
    if (a == '{' && b == '}')
    {
        return 1;
    }

    if (a == '(' && b == ')')
    {
        return 1;
    }

    if (a == '[' && b == ']')
    {
        return 1;
    }

    return 0;
}

int main()
{
    cout << "**************Multiple-Parenthesis Matching Code*************" << endl;

    cout << " { ( [ ------> PUSH into the stack " << endl;
    cout << " } ) ] ------> POP out of the stack " << endl
         << endl;

    cout << "        |            |" << endl;
    cout << "        |            |" << endl;
    cout << "        |            |" << endl;
    cout << "        |            |" << endl;
    cout << "        --------------" << endl
         << endl;

    cout << "NOTE:: check TOP of the stack before pop operation in Multiple parenthesis " << endl;
    cout << "                      |-------------> }     pop operation is possible (parenthesis are same)                  " << endl;
    cout << "          |           |   |" << endl;
    cout << " TOP--->  |     { <---|   |" << endl;
    cout << "          |     [         |" << endl;
    cout << "          |     (         |" << endl;
    cout << "          -----------------" << endl
         << endl;

    cout << "                      |-------------> ]     pop operation is NOT possible  (parenthesis are different)          " << endl;
    cout << "          |           |   |" << endl;
    cout << " TOP--->  |     { <---|   |" << endl;
    cout << "          |     [         |" << endl;
    cout << "          |     (         |" << endl;
    cout << "          -----------------" << endl
         << endl;

    cout << "Using Stack for MUltiple Parenthesis Matching ( Implementation of stack using array ) " << endl;
    Stack Object;
    Stack *ptr;
    ptr = &Object;

    // Check parenthesis Matching
    const char *exp = "{[8*(9+5)}]";
    cout << endl
         << "String ::  {[8*(9+5)}]" << endl
         << endl;
    cout << "------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|    {    |    [    |    8    |    *    |    (    |    9     |    +     |    5    |    )    |     }    |    ]    |" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------" << endl
         << endl;

    if (Object.paraenthesisMatching(exp, ptr))
    {
        cout << "The parenthesis is Matching (***Balanced***)" << endl;
    }
    else
    {
        cout << "The parenthesis is not matching (***Unbalanced***)" << endl;
    }
    cout << "for pop operation in multiple paraenthesis take place only when last push element in stack is same as pop element" << endl;

    return 0;
}