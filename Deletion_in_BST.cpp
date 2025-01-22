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
    void InOrderTraversal(Node *root);
    int isBST(Node *root);
    Node *search_Iterative(Node *root, int key);
    Node *deleteNode(Node *root, int value);
    Node *inOrderPredecessor(Node *root);
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
    Node *p = createNode(8);
    Node *p1 = createNode(3);
    Node *p2 = createNode(10);
    Node *p3 = createNode(1);
    Node *p4 = createNode(6);
    Node *p5 = createNode(4);
    Node *p6 = createNode(7);
    Node *p7 = createNode(14);
    Node *p8 = createNode(13);

    // p1<--p-->p2;
    p->left = p1;
    p->right = p2;

    // p3<--p1-->p4;

    p1->left = p3;
    p1->right = p4;

    // NULL<--p2-->p7;

    p2->right = p7;

    // p8<--p2-->NULL;
    p7->left = p8;

    // p5<--p4-->p6;

    p4->left = p5;
    p4->right = p6;

    return p;
}

void Tree::InOrderTraversal(Node *root)
{
    if (root != NULL)
    {

        InOrderTraversal(root->left);
        cout << root->data << "  ";
        InOrderTraversal(root->right);
    }
}

int Tree::isBST(Node *root)
{
    if (root != NULL)
    {

        static Node *prev = NULL; // Note static :: value not differe for different call

        if (!isBST(root->left))
        {
            return 0;
        }

        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }

    else
    {
        return 1; // Empty tree is assumed as BST
    }
}

Node *Tree::search_Iterative(Node *root, int key)
{
    while (root != NULL)
    {

        if (key == root->data)
        {                // key is equal to root
            return root; // element found
        }
        else if (key < root->data)
        {                      // key is lesser then root
            root = root->left; // go for left subtree
        }
        else
        {                       // key is greater then root
            root = root->right; // go for right subtree
        }
    }
    return NULL; // element not found
}

Node *Tree::inOrderPredecessor(Node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

Node *Tree ::deleteNode(Node *root, int value)
{
    Node *iPre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        delete root;
        return NULL;
    }

    // Search for the node to be delete
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    // Deletion strategy when the node is found
    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }

    return root;
}

int main()
{
    Tree Object;
    Node *root = Object.createTree();

    cout << "******************Deletion in Binary Search Tree******************" << endl
         << endl;
    cout << "******************Before Deletion  ::************************************" << endl;

    cout << "NOTE::: Inorder Traversal of a BST gives an Ascending Sorted array" << endl
         << endl;

    if (Object.isBST(root))
    {
        cout << "Tree 1 is Binary Search Tree  " << endl;
    }
    else
    {
        cout << "Tree 1 is NOT a Binary Search Tree  " << endl;
    }

    cout << "Searching for ----> 8 " << endl;

    cout << "******InOrder Traversal of BST ************" << endl;
    Object.InOrderTraversal(root);
    cout << "    ---------------> Sorted " << endl
         << endl;

    cout << endl
         << endl;

    cout << "************Iterative Search in BST ************" << endl;
    // Iterative Approach is used below
    Node *m = Object.search_Iterative(root, 8);
    if (m != NULL)
    {
        cout << "Found :: " << m->data << endl;
        cout << "Element found in BST" << endl;
    }
    else
    {
        cout << "Element not found in BST " << endl;
    }

    cout << "Deleting ----> 8 " << endl;
    Object.deleteNode(root, 8); // Deleting ---->  7

    cout << "******************After Deletion ::************************************" << endl
         << endl;
    cout << "NOTE::: Inorder Traversal of a BST gives an Ascending Sorted array" << endl
         << endl;

    cout << "******InOrder Traversal of BST************" << endl;
    Object.InOrderTraversal(root);
    cout << "    ---------------> Sorted " << endl
         << endl;

    cout << endl
         << endl;
    cout << "************Iterative Search in BST ************" << endl;
    // Iterative Approach is used below
    Node *n = Object.search_Iterative(root, 8);
    if (n != NULL)
    {
        cout << "Found :: " << n->data << endl;
        cout << "Element found in BST" << endl;
    }
    else
    {
        cout << "Element not found in BST " << endl;
    }

    return 0;
}

// Deletion a node in a BST :::
// Look simple to find element like and then delete but is complex
//
// Case-1::The node is a leaf node
//                          8
//                       /    |
//                      3     10
//                    /  |      |
//                   1   6     14
//                      / |    /
//          Delete---->4* 7   13
//          Node 4
//
// Step-1:: Search the node {using search function}
// Step-2:: Delete the node {delete the pointer and free memory}
//
// Case-2::The node is a non-leaf node
//                          8
//                       /    |
//                      3     10
//                  /   |      |
//                1 |-->6*    14
//     Delete-------| /  |    /
//     Node 6        4   7   13
//                                                                                              o
// Inoreder Traversal of BST ::  1 3 4 6 7 8 10 13 14                                     o    -|-
//                                   ^ ^ ^                                          o    -|-    |
// Inoreder pre (Predecessor)--------| | |-------Inoreder post (Successor)         -|-    |     |
//                                  given node                                      ^     ^     ^
//                                                                                chota  Aap   Bada
//                                                                              //1.chota ,Bada se bhi chota hai
//                                                                              //2.Bada  ,chota se bhi bada hai
//{After deleting 6 from BST then Replace by 4 or 7 }
//
//                          8                                  8
//                       /    |                             /    |
//                      3     10                           3     10
//                    /  |      |           or           /  |      |
//                   1   4     14                       1   7     14
//                        |    /                            /     /
//                        7   13                           4     13
//                   Correct BST                         Correct BST
//
// Step-1:: Search for the node {using search function}
// Step-2:: Search for the Inoreder pre (Predecessor) and Inoreder post (Successor)  {Creating function to find these two node Predecessor and Successor}
// Step-3:: Replace Predecessor or Successor with Deleted  node {delete the pointer and free memory}
//
// Case-3::The node is a Root node
//                          8* ---->Delete Node 8
//                       /    |
//                      3     10
//                    /  |      |
//                   1   6     14
//                      / |    /
//                     4  7   13
//
// Inoreder Traversal of BST ::  1 3 4 6 7 8 10 13 14
//                                       ^ ^ ^
//     Inoreder pre (Predecessor)--------| | |-------Inoreder post (Successor)
//                                        Root
//
//                          7 ---->{Replaced with Predecessor } {Try to replace by leaf node}
//                       /    |
//                      3     10
//                    /  |      |
//                   1   6     14
//                      / |    /
//                     4 NULL 13
//
//
//                          10 ---->{Replaced with Successor }
//                       /    |
//                      3     ---  --->Empty node
//                    /  |      |
//                   1   6     14
//                      / |    /
//                     4  7   13
// Inoreder Traversal of BST ::  1 3 4 6 7 8 10 13 14
//                                         ^  ^  ^
//       Inoreder pre (Predecessor)--------|  |  |-------Inoreder post (Successor)
//       But is deleted go for               Root
//       Successor is only
//       possible
//
//
//
//                          10
//                       /    |
//                      3      13  ---->{Replaced with Successor }
//                    /  |      |
//                   1   6     14
//                      / |    /
//                     4  7   --   --->Empty node is leaf node delete it
// Step-1:: Search for the node {using search function}
// Step-2:: Search for the Inoreder pre (Predecessor) and Inoreder post (Successor)  {Creating function to find these two node Predecessor and Successor}
// Step-3:: Replace Predecessor or Successor with Deleted  node {delete the pointer and free memory}
// Step-4:: Keep doing this until the free has no empty node {Recursively repeate till getting leaf node then delete that leaf node}