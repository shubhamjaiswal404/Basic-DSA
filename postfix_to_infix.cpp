// LEARN STRINGS THEN DOTHIS BECAUSE IT BECOME COMPLEX IN CHAR 
#include <iostream>
#include <cstring>
using namespace std;

class Stack
{

public:
    int size;
    int top;
    char *arr;
    char *arr1;
    char *arr2;
    char *arr3;
    int isEmpty(Stack *ptr);
    int isFull(Stack *ptr);
    void push(Stack *ptr, char value);
    char pop(Stack *ptr);
    int precedence(const char ch);
    int isOperator(const char ch);
    char *PostfixToInfix(const char *infix, Stack *sp,Stack *sp2,Stack *sp3);
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

char *Stack::PostfixToInfix(const char *postfix, Stack *sp1,Stack *sp2,Stack *sp3)
{
    sp1->size = 100;
    sp1->top = -1;
    sp1->arr1 = new char[sp1->size];

    sp2->size = 100;
    sp2->top = -1;
    sp2->arr2 = new char[sp2->size];

    sp3->size = 100;
    sp3->top = -1;
    sp3->arr3 = new char[sp3->size];

    char *Infix = new char[strlen(postfix) + 1];

    // Stack *sp=new Stack();

    int i = 0; // Track infix Traversal
    // int j = 0; // Track postfix addition

    while (postfix[i] != '\0')
    {
        cout<<"shubham"<<endl;
        // cout<<" J"<<postfix[i]<<endl;
        // i++;
        // cout<<" J"<<postfix[i]<<endl;
        // i++;
        // i++;
        if (!isOperator(postfix[i]))
        {
        cout<<" J"<<postfix[i]<<endl;
            // postfix[j] = infix[i];
            push(sp1,postfix[i]);
            i++;
        }
        else if(isOperator(postfix[i+1] && isOperator(postfix[i]) )){

                if(!isEmpty(sp1)){
                char op1 = pop(sp1);
                push(sp3,op1);
                }

                char opt = postfix[i+1];

                char op_1 = pop(sp2);
                char op_t = pop(sp2);
                char op_2 = pop(sp2);


                push(sp3,opt);
                push(sp3,op_1);
                push(sp3,op_t);
                push(sp3,op_2);

                i++;


        }
        else
        {
        cout<<" J"<<postfix[i]<<endl;
            char op1 = pop(sp1);
            char op2 = pop(sp1);
            char opt = postfix[i];

            push(sp2,op2);
            push(sp2,opt);
            push(sp2,op1);

            i++;
            // char op1=pop(sp);
            // char op2=pop(sp);

            // x y z / - k d * + 
            // push1 x  y  z  
            // st1 x 
            // pop1 z  y 
            // push2 y  exp  z
            // st2 y / z
            // pop1 x
            // pop2 z  /  y
            // push2 x  - push2 (push2 y  exp  z)
            // st2 x- y/z
            // push1 k  d  
            // st1 k d
            // pop1 d  k
        
            // pop2 d  *  k 
            // pop2 z /   y   -  x
            // push2 x - y / z push1 + push k * d 
            // x-y/z+k*d
           
        }
    }

    int j = strlen(postfix)+1;
    while (!isEmpty(sp3))
    {
        // cout<<"shubham"<<endl;

        Infix[j] = pop(sp3);
        cout<<Infix[j];
        j--;
    }

    

    Infix[j] = '\0';
    return Infix;
}

int main()
{

    Stack Object1,Object2,Object3,Object;
    Stack *ptr1;
    Stack *ptr2;
    Stack *ptr3;
    ptr1 = &Object1;
    ptr2 = &Object2;
    ptr3 = &Object3;


    // ptr->size = 100;
    // ptr->top = -1;
    // ptr->arr = new char[ptr->size];

    const char *Infix_exp = "xyz/-kd*+";

    

    cout << "Infix Experssion :: " << Infix_exp << endl;
    cout << "After convertion from Infix Expression to Postfix Experssion" << endl;

    cout << "Postfix Experssion :: " << Object1.PostfixToInfix(Infix_exp, ptr1,ptr2,ptr3) << endl;

    return 0;
}


//      /----|----|----|----|-----\
//     /     |    |    |    |      \
//    /     /|----|----|----|\      \
//   /     /                  \      \
//  (-----(                    )------)
//   \     \                  /      /
//    \     \|----|----|----|/      /
//     \     |    |    |    |      /
//      \----|----|----|----|-----/