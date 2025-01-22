#include<iostream>
using namespace std;

struct Node{
    int data;
    Node*next;
};

class Linkedlist{

     int value1,value2,value3,value4;
   public:
     Node*head;
    //  intializing constructor head to NULL
        Linkedlist():head(NULL){};

       void createLinkedlist(int value1,int value2,int value3,int value4) {
        //Creating Nodes and Allocate memory for Node in linkedlist
        Node* firstNode = new Node(); 
        Node* secondNode = new Node(); 
        Node* thirdNode = new Node(); 
        Node* fourthNode = new Node(); 

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

        // fourthNode link with NULL (linkedlist end or terminates)
        fourthNode->data = value4;      
        fourthNode->next = NULL;       
                    
    cout<<endl<<"Linkedlist:: HEAD --->"<<firstNode->data<<"--->"<<secondNode->data<<"--->"<<thirdNode->data<<"--->"<<fourthNode->data<<"---> NULL"<<endl;
    cout<<"address of head ::"<<firstNode<<endl
    <<"address of firstNode::"<<secondNode<<endl
    <<"address of secondNode::"<<thirdNode<<endl
    <<"address of thirdNode::"<<fourthNode<<endl<<endl;
    }


};


void linkedlistTravesal(struct Node*firstNode){
    
    cout<<"************Traversal (For understanding prefer while loop method below)************"<<endl;
    struct Node*secondNode;
    struct Node*thirdNode;
    struct Node*fourthNode;

    // cout<<first->next<<endl;
    cout<<"Address of head pointing firstNode ::"<<firstNode<<endl;
    cout<<"value in firstNode "<<firstNode->data<<endl<<endl;
    secondNode=firstNode->next;

    cout<<"Address of firstNode pointing secondNode:: "<<secondNode<<endl;
    cout<<"value in secondNode "<<secondNode->data<<endl<<endl;
    thirdNode=secondNode->next;

    cout<<"Address of secondNode pointing thirdNode:: "<<thirdNode<<endl;
    cout<<"value in thirdNode "<<thirdNode->data<<endl<<endl;

    fourthNode=thirdNode->next;

    cout<<"Address of thirdNode pointing fourthNode::"<<fourthNode<<endl;
    cout<<"value in fourthNode "<<fourthNode->data<<endl<<endl;

    cout<<"************Traversal (while loop method)************"<<endl;

    while(firstNode!=NULL){
    cout<<firstNode->data<<endl;
    firstNode=firstNode->next;

    }

}


int main(){
    cout<<"************Linkedlist Creation and Traversal************"<<endl;
    Linkedlist Object;
    Object.createLinkedlist(7,8,22,11);
    linkedlistTravesal(Object.head);

    

    return 0;
}

//linkedlist creation  + traversal
// 
// Linkedlist 

//     HEAD|address of 7(0xf519e0)|--->|7| address of 8(0xf51558) |--->|8| address of 22(0xf51568)|--->|22| address of 11(0xf51578)|--->|11| address of NULL|--->NULL

//                                        firstNode         ------>         secondNode        ------>         thirdNode     ------>           fourthNode

// struct Node 
// |7| address of 8(0x11019e0)|
//  ^           ^ 
//  |           |
// int      sturct Node 
// (value)   (pointer)












