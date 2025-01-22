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
     Node*secondNode;       //NOTE::: for this function---> insertAfterNode()
    //  intializing constructor head to NULL
        Linkedlist():head(NULL){};
        void linkedlistTravesal(Node*head);
        Node* insertAtFirst(Node* head,int data);
        Node* insertAtEnd(Node* head,int data);
        Node* insertAfterNode(Node* head,Node* pre,int data);
        Node* insertAtIndex(Node* head,int data,int index);

       Node* createLinkedlist(int value1,int value2,int value3,int value4) {   //NOTE::: for this function---> insertAfterNode()
    //    void createLinkedlist(int value1,int value2,int value3,int value4) { 
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
                    
    cout<<endl<<"Linkedlist Before insertion:: HEAD --->"<<firstNode->data<<"--->"<<secondNode->data<<"--->"<<thirdNode->data<<"--->"<<fourthNode->data<<"---> NULL"<<endl;
    cout<<"address of head ::"<<firstNode<<endl
    <<"address of firstNode::"<<secondNode<<endl
    <<"address of secondNode::"<<thirdNode<<endl
    <<"address of thirdNode::"<<fourthNode<<endl<<endl;


      return secondNode;        //NOTE::: for this function---> insertAfterNode()
      
    }


};

Node* Linkedlist::insertAtFirst(Node*head,int data){
    cout<<"***********insertAtFirst***********"<<endl;
    Node* newNode=new Node();
    newNode->next=head;
    newNode->data=data;
    return newNode;
}

Node* Linkedlist::insertAtIndex(Node*head,int data,int index){
    cout<<"***********insertAtIndex***********"<<endl;
    Node* newNode=new Node();
    Node*p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    newNode->next=p->next;
    p->next=newNode;
    newNode->data=data;
    return head;
}

Node* Linkedlist::insertAfterNode(Node*head,Node*pre,int data){
    cout<<"***********insertAfterNode***********"<<endl;
    Node* newNode=new Node();

    newNode->next=pre->next;
    pre->next=newNode;
    newNode->data=data;
    return head;
}

Node* Linkedlist::insertAtEnd(Node*head,int data){
    cout<<"***********insertAtEnd***********"<<endl;
    Node* newNode=new Node();
    Node*p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=newNode;
    newNode->next=NULL;
    newNode->data=data;
    return head;
}





void Linkedlist :: linkedlistTravesal(Node*firstNode){
    
    Node*secondNode;
    Node*thirdNode;
    Node*fourthNode;
    Node*fifthNode;

    cout<<endl<<"************Traversal (For understanding prefer while loop method below)************"<<endl;
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
    fifthNode=fourthNode->next;

    cout<<"Address of head pointing fifthNode ::"<<fifthNode<<endl;
    cout<<"value in fifthNode "<<fifthNode->data<<endl<<endl;


    cout<<endl<<"Linkedlist After insertion:: HEAD --->"<<firstNode->data<<"--->"<<secondNode->data<<"--->"<<thirdNode->data<<"--->"<<fourthNode->data<<"---> "<<fifthNode->data<<"---> NULL"<<endl<<endl;

    cout<<"************Traversal (while loop method)************"<<endl;

    while(firstNode!=NULL){
    cout<<firstNode->data<<endl;
    firstNode=firstNode->next;

    }

}


int main(){
    cout<<"************Insertion in Linkedlist ************"<<endl;
    Linkedlist Object;

    Object.secondNode=Object.createLinkedlist(7,8,22,11); //  //NOTE::: for this function---> insertAfterNode()
    // Object.createLinkedlist(7,8,22,11);
    // Object.head=Object.insertAtFirst(Object.head,12);
    // Object.head=Object.insertAtEnd(Object.head,12);
    // Object.head=Object.insertAtIndex(Object.head,12,2);
    Object.head=Object.insertAfterNode(Object.head,Object.secondNode,12); //   //NOTE::: for this function---> insertAfterNode()
    Object.linkedlistTravesal(Object.head);


    cout<<"NOTE:: Only insertion functions are introduce in yesterday code and Linkedlist creation "<<endl;

    

    return 0;
}



// ************Insertion in Linkedlist ************

// ***********insertAtFirst***********
// Linkedlist Before insertion:: HEAD --->7--->8--->22--->11---> NULL
// Linkedlist After insertion:: HEAD --->12--->7--->8--->22---> 11---> NULL

// ***********insertAtEnd***********
// Linkedlist Before insertion:: HEAD --->7--->8--->22--->11---> NULL
// Linkedlist After insertion:: HEAD --->7--->8--->22--->11---> 12---> NULL

// ***********insertAtIndex***********
// Linkedlist Before insertion:: HEAD --->7--->8--->22--->11---> NULL
// Linkedlist After insertion:: HEAD --->7--->8--->12--->22---> 11---> NULL

// ***********insertAfterNode***********
// Linkedlist Before insertion:: HEAD --->7--->8--->22--->11---> NULL
// Linkedlist After insertion:: HEAD --->7--->8--->12--->22---> 11---> NULL
