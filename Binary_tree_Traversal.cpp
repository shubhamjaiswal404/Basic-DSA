#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Tree
{
public:
    Node *createTree();
    Node *createNode(int value);
    void preOrderTraversal(Node *root);
    void InOrderTraversal(Node *root);
    void postOrderTraversal(Node *root);
};

Node *Tree::createNode(int value)
{
    Node *n = new Node();
    n->data = value;
    n->left = NULL;
    n->right = NULL;

    return n;
}

Node *Tree::createTree()
{
    Node *p = createNode(4);
    Node *p1 = createNode(1);
    Node *p2 = createNode(6);
    Node *p3 = createNode(5);
    Node *p4 = createNode(2);

    // p1<--p-->p2;
    p->left = p1;
    p->right = p2;

    // p3<--p1-->p4;

    p1->left = p3;
    p1->right = p4;

    return p;
}

void Tree::preOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << endl;
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void Tree::postOrderTraversal(Node *root)
{
    if (root != NULL)
    {

        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << endl;
    }
}

void Tree::InOrderTraversal(Node *root)
{
    if (root != NULL)
    {

        InOrderTraversal(root->left);
        cout << root->data << endl;
        InOrderTraversal(root->right);
    }
}

int main()
{
    Tree Object;
    Node *root = Object.createTree();
    cout << "******PreOrder Traversal ************" << endl;
    Object.preOrderTraversal(root);
    cout << "******InOrder Traversal ************" << endl;
    Object.InOrderTraversal(root);
    cout << "******PostOrder Traversal ************" << endl;
    Object.postOrderTraversal(root);

    return 0;
}

//      4
//    /   |
//   1    6
//  /  |
// 5   2



// DSA
// C++
// GIT
// 
// 
