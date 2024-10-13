#include<iostream>
using namespace std;
struct Node
{
   int data;
    Node*left;
    Node*right;  
};


class Tree{
    public:
    
    void createTree();//Only for understanding
    void createNode_Tree();//Recommended
    
};

void Tree::createTree(){
    // Constructing the root node 
    Node* p= new Node();
    p->left=NULL;
    p->data=2;
    p->right=NULL;
    // Constructing the second node 
    Node* p1= new Node();
    p1->left=NULL;
    p1->data=1;
    p1->right=NULL;
    // Constructing the third node 
    Node* p2= new Node();
    p2->left=NULL;
    p2->data=4;
    p2->right=NULL;

//  Linking the root node with left and right children
    p->left=p1;
    p->right=p2;
    

}

Node* createNode(int value){
    // Allocating memory
    Node* n= new Node();
    n->data=value;
    n->left=NULL;
    n->right=NULL;

    return n;

}

//Constructing the root node-using function (Recommended)
void Tree:: createNode_Tree(){
    //constructing the root node
    Node* p=createNode(2);
    Node* p1=createNode(4);
    Node* p2=createNode(1);
    // Linking the root node with left and right children
    p->left=p1;
    p->right=p2;

}


int main(){
    cout<<"***********Creation of Tree***********"<<endl<<endl;
    Tree Object;
    Object.createTree();//Only for understanding
    Object.createNode_Tree();//Recommended
    cout<<"    ( 2 )---> Root Node "<<endl;
    cout<<"    /  |           "<<endl;
    cout<<" NULL  NULL    "<<endl<<endl;

    cout<<"    ( 4 )---> second Node "<<endl;
    cout<<"   /   |           "<<endl;
    cout<<" NULL  NULL    "<<endl<<endl;

    cout<<"    ( 1 )---> third Node "<<endl;
    cout<<"   /   |           "<<endl;
    cout<<" NULL  NULL    "<<endl<<endl;

    cout<<" Linking the root node with left and right children"<<endl;
    cout<<"        ( 2 )---> Root Node "<<endl;
    cout<<"       /    |           "<<endl;
    cout<<"     (1)   (4)    "<<endl;
    cout<<"    /  |   / |         "<<endl;
    cout<<" NULL NULL NULL NULL   "<<endl<<endl;

    
    return 0;
}