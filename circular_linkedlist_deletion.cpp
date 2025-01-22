#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Linkedlist
{

    int value1, value2, value3, value4,value5;

public:
    Node *head;
    //  intializing constructor head to NULL
    Linkedlist() : head(NULL) {};

    Node* deleteFirst(Node*head);
    Node* deleteAtIndex(Node*head,int index);
    Node* deleteAfterNode(Node*head,int value);
    Node* deleteAtLast(Node*head);
    void linkedlistTravesal(Node *firstNode);

    void createLinkedlist(int value1, int value2, int value3, int value4,int value5)
    {
        // Creating Nodes and Allocate memory for Node in linkedlist
        Node *firstNode = new Node();
        Node *secondNode = new Node();
        Node *thirdNode = new Node();
        Node *fourthNode = new Node();
        Node *fifthNode = new Node();

        // head link with firstNode (linkedlist start)
        head = firstNode;

        // firstNode link with secondNode
        firstNode->data = value1;
        firstNode->next = secondNode;

        // secondNode link with thirdNode
        secondNode->data = value2;
        secondNode->next = thirdNode;

        // thirdNode link with fourthNode
        thirdNode->data = value3;
        thirdNode->next = fourthNode;

        // fourthNode link with fifthNode 
        fourthNode->data = value4;
        fourthNode->next = fifthNode;

        // fifthNode link with HEAD (linkedlist never end or terminates)
        fifthNode->data = value5;
        fifthNode->next = firstNode;

        

         cout << endl
         << "Linkedlist:: HEAD --->" << firstNode->data << "--->" << secondNode->data << "--->" << thirdNode->data << "--->" << fourthNode->data << "--->" << fifthNode->data << "---| " << endl;
    cout << "                      ^                          | " << endl;
    cout << "                      |                          |" << endl;
    cout << "                      |--------------------------|" << endl
         << endl;


        cout << "address of head ::" << firstNode << " <--- same " << endl
             << "address of firstNode::" << secondNode << endl
             << "address of secondNode::" << thirdNode << endl
             << "address of thirdNode::" << fourthNode << endl
             << "address of fourthNode::" << fifthNode << endl
             << "address of fifthNode::" << fifthNode->next << " <--- same " << endl
             << endl;
    }
};


Node* Linkedlist::deleteAtLast(Node*head){
    cout<<"***********deleteAtEnd***********"<<endl;
    Node*p=head;
    Node*q=head->next;

    // q point to last element of circular linkedlist
    while(q->next!=head){
        p=p->next;
        q=q->next;
    }


    // do
    // {
    //     p=p->next;
    //     q=q->next;
    // } while (q->next!=head);

    p->next=head; // second last element of circular linkedlist
    delete q;
    return head;
}


Node* Linkedlist::deleteFirst(Node*head){
    cout<<"***********deleteFirst***********"<<endl;
    Node*newNode=head;
    do
    {
        newNode=newNode->next;
    } while (newNode->next!=head->next);

    newNode->next=head->next;

    head=head->next;

    delete newNode;
    return head;
}


Node* Linkedlist::deleteAfterNode(Node*head,int value){ // NOTE :: value is given 
    cout<<"***********deleteAfterNode***********"<<endl;
    Node*p=head;
    Node*q=head->next;

    while(q->data!=value && q->next!=p){
        p=p->next;
        q=q->next;
    }

    if(q->data=value){
        p->next=q->next;
        delete q;
    }
    return head;
}



Node* Linkedlist::deleteAtIndex(Node*head,int index){
    cout<<"***********deleteAtIndex***********"<<endl;
    Node*p=head;
    Node*q=head->next;
    int i=0;
    while(i!=index-1){
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    delete q;
    return head;
}



void Linkedlist ::linkedlistTravesal(Node *firstNode)
{

    cout << "************Traversal (For understanding prefer while loop method below)************" << endl;
    Node *secondNode;
    Node *thirdNode;
    Node *fourthNode;
    Node *fifthNode;

    Node *ptr = firstNode; // firstNode is head [pointer]

    // cout<<first->next<<endl;

    cout << "Address of head pointing firstNode ::" << firstNode << endl;
    cout << "value in firstNode " << firstNode->data << endl
         << endl;
    secondNode = firstNode->next;

    cout << "Address of firstNode pointing secondNode:: " << secondNode << endl;
    cout << "value in secondNode " << secondNode->data << endl
         << endl;
    thirdNode = secondNode->next;

    cout << "Address of secondNode pointing thirdNode:: " << thirdNode << endl;
    cout << "value in thirdNode " << thirdNode->data << endl
         << endl;

    fourthNode = thirdNode->next;

    cout << "Address of thirdNode pointing fourthNode::" << fourthNode << endl;
    cout << "value in fourthNode " << fourthNode->data << endl
         << endl;

    fifthNode = fourthNode->next;
    // cout << "Address of head pointing fifthNode ::" << fifthNode << endl;
    // cout << "value in fifthNode " << fifthNode->data << endl
    //      << endl;

    cout << "************Traversal (while loop and do-while method)************" << endl;

    cout << "***********using While loop***********" << endl;
    cout << "Element of Circular linkedlist :: " << ptr->data << endl;
    ptr = ptr->next;
    while (ptr != fifthNode)
    {
        cout << "Element of Circular linkedlist :: " << ptr->data << endl;
        ptr = ptr->next;
    }
    cout << endl;

    ptr = firstNode;

    cout << "***********using Do-While loop(prefer do-while loop in circular traversal)***********" << endl;

    do
    {
        cout << "Element of Circular linkedlist :: " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != fifthNode);
    cout << endl;

    cout << endl
         << "Linkedlist:: HEAD --->" << firstNode->data << "--->" << secondNode->data << "--->" << thirdNode->data << "--->" << fourthNode->data <<  "---| " << endl;
    cout << "                      ^                     | " << endl;
    cout << "                      |                     |" << endl;
    cout << "                      |---------------------|" << endl
         << endl;
    cout << "address of head ::" << firstNode << " <--- same " << endl
         << "address of firstNode::" << secondNode << endl
         << "address of secondNode::" << thirdNode << endl
         << "address of thirdNode::" << fourthNode << endl
         << "address of fourthNode:" << fifthNode << " <--- same " << endl
         << endl;
}

int main()
{
    cout << "************Deletion in Circular linkedlist ************" << endl;
    Linkedlist Object;
    Object.createLinkedlist(7, 8, 22, 11,54);
    // Object.head=Object.deleteFirst(Object.head);
    // Object.head=Object.deleteAfterNode(Object.head,8);
    // Object.head=Object.deleteAtIndex(Object.head,1);
    Object.head=Object.deleteAtLast(Object.head);
    Object.linkedlistTravesal(Object.head);

    return 0;
}