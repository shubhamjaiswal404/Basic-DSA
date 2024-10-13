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
    int paraenthesisMatching(const char*exp,Stack* sp);

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



int Stack :: paraenthesisMatching(const char*exp,Stack* sp){
    
    sp->size=100;
    sp->top=-1;
    sp->arr=new char[sp->size];

    //Creation and initialization the stack
    for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='('){
            push(sp,'(');
        cout << "  PUSH---> |     (      |" << endl;
        cout << "           |            |" << endl;
        cout << "           --------------" << endl;

        }
        else if(exp[i]==')'){
            if(isEmpty(sp)){
                 cout << "******Stack Underflow******" << endl;
                 cout << "   POP---> |      )     |<------ Not possible because Stack is empty" << endl;
                 cout << "           |            |" << endl;
                 cout << "           --------------" << endl;
                return 0;
            }
            pop(sp);
        cout << "   POP---> |     )      |" << endl;
        cout << "           |            |" << endl;
        cout << "           --------------" << endl;
            


        }
    }

    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
    

}

int main()
{
    cout << "**************Parenthesis Matching Code*************" << endl;

    cout<<" ( ------> PUSH into the stack "<<endl;
    cout<<" ) ------> POP out of the stack "<<endl<<endl;


    cout << "        |            |" << endl;
    cout << "        |            |" << endl;
    cout << "        |            |" << endl;
    cout << "        |            |" << endl;
    cout << "        --------------" << endl;
   
    cout << "Using Stack for parenthesis matching ( Implementation of stack using array ) " << endl;
    Stack Object;
    Stack *ptr;
    ptr = &Object;

    // ptr->size = 100;
    // ptr->top = -1;
    // ptr->arr = new char[ptr->size];



    // Check parenthesis Matching
    const char* exp="(8*(9+5))";
    cout<<endl<<"String ::  (8*(9+5))"<<endl<<endl;
    cout<<"----------------------------------------------------------------------------------------------"<<endl;
    cout<<"|    (    |    8    |    *    |    (    |    9     |    +     |    5    |    )    |     )    |"<<endl;
    cout<<"----------------------------------------------------------------------------------------------"<<endl<<endl;


    if(Object.paraenthesisMatching(exp,ptr)){
        cout<<"The parenthesis is Matching (***Balanced***)"<<endl;
    }
    else{
        cout<<"The parenthesis is not matching (***Unbalanced***)"<<endl;
    }
   
    return 0;
}