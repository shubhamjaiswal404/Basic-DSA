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
    Node *p = createNode(9);
    Node *p1 = createNode(4);
    Node *p2 = createNode(11);
    Node *p3 = createNode(2);
    Node *p4 = createNode(7);
    Node *p5 = createNode(5);
    Node *p6 = createNode(8);
    Node *p7 = createNode(15);
    Node *p8 = createNode(14);

    // p1<--p-->p2;
    p->left = p1;
    p->right = p2;

    // p3<--p1-->p4;

    p1->left = p3;
    p1->right = p4;

    // p5<--p4-->p6;

    p4->left = p5;
    p4->right = p6;

    // NULL<--p2-->p7;
    p2->right = p7;

    // p8<--p7-->NULL;
    p7->left = p8;

    return p;
}

void Tree::preOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << "  ";
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
        cout << root->data << "  ";
    }
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

int main()
{
    Tree Object;
    Node *root = Object.createTree();
    cout << "******PreOrder Traversal ************" << endl;
    Object.preOrderTraversal(root);
    cout<<endl;
    cout << "******InOrder Traversal ************" << endl;
    Object.InOrderTraversal(root);
    cout<<endl;
    cout << "******PostOrder Traversal ************" << endl;
    Object.postOrderTraversal(root);

    return 0;
}

//******PreOrder Traversal ************
//  Root---->Leftsubtree---->Rightsubtree
//
//                         9*               ==> 9 [4  [2]  [7  [5]  [8] ] ]   [11 [15  [ 14 ] ] ]
//                       /    |             ==> 9 4 2 7 5 8 11 15 14
//                      4     11
//                    /  |      |
//                   2   7     15
//                      / |    /
//                     5  8   14
//

// Preorder Traversal function print Root Node
//                               9*  ----------->     Root             ==> 9 {4  [2]  [7  [5]  [8] ] }   {11 [15  [ 14 ] ] }
//                             /         |
//                  |-----------|     |-----------|                   ==> 9
//                  |    4      |     |  11       |
//                  |   /  |    |     |  |        |
//                  |  2   7    |     | 15        |
//                  |     / |   |     | /         |
//                  |    5  8   |     | 14        |
//                  |-----------|     |-----------|
//                   Leftsubtree-1      Rightsubtree-1

// Now going to Leftsubtree-1 ::::
//
//                          4* -------->Root         ==> 4  {2}  {7  [5]  [8] }
//                     /        |
//                 |---|    |-------|                ==> 9 4
//                 | 2 |    |    7  |
//                 |---|    |   / | |
//          Leftsubtree-2   |  5  8 |
//                          |-------|
//                          Rightsubtree-2

// Now going to Leftsubtree-2 :::: (NOTE:: there is no Leftsubtree and Rightsubtree of Node 2 )
//
//                      2* ------------>Root    ==> 2
//                                              ==> 9 4 2

// Now going to Rightsubtree-2  :::::::
//
//                      7*--------->Root       ==> 7  {5}  {8}
//                   /     |                   ==> 9 4 2 7
//               |----|  |----|
//               | 5  |  | 8  |
//               |----|  |----|
//       Leftsubtree-3   Rightsubtree-3

// Now going to Leftsubtree-3  :::::: (NOTE:: there is no Leftsubtree and Rightsubtree of Node 5 )
//
//                      5* ------------>Root    ==> 5
//                                              ==> 9 4 2 7 5

// Now going to Rightsubtree-3 ::::::: (NOTE:: there is no Leftsubtree and Rightsubtree of Node 8 )
//
//                      8* ------------>Root    ==> 8
//                                              ==> 9 4 2 7 5 8
//
// Now going to Rightsubtree-1 ::::
//
//
//                       11* ---------->Root     ==>  11 {15  [ 14 ] }
//                         |                     ==> 9 4 2 7 5 8 11
//                      |-------|
//                      |   15  |
//                      |  /    |
//                      | 14    |
//                      |-------|
//                   Rightsubtree-4

// Now going to Rightsubtree-4 ::::::
//
//                          15* ------>Root   ==>    15  { 14 }
//                         /                  ==> 9 4 2 7 5 8 11 15
//                      |-----|
//                      | 14  |
//                      |-----|
//                     Leftsubtree-5

// Now going to Leftsubtree-5 ::::::: (NOTE:: there is no Leftsubtree and Rightsubtree of Node 14 )
//
//                      14* ------------>Root    ==> 14
//                                               ==>  9 4 2 7 5 8 11 15 14


// ############################################################################################################


//******PostOrder Traversal ************
//  Leftsubtree---->Rightsubtree---->Root
//
//                         9                ==> [ [2]  [ [5]  [8]  7 ] 4]   [ [  [ 14 ] 15 ] 11]  9
//                       /    |             ==> 2 5 8 7 4 14 15 11 9
//                      4     11                
//                    /  |      |
//                   2   7     15
//                      / |    /
//                     5  8   14
//

// Postorder Traversal function print Root Node
//                               9  ----------->     Root             ==> {  [2]  [  [5]  [8] 7 ]  4}   { [ [ 14 ] 15] 11} 9
//                             /         |
//                  |-----------|     |-----------|                   ==> 
//                  |    4      |     |  11       |
//                  |   /  |    |     |  |        |
//                  |  2   7    |     | 15        |
//                  |     / |   |     | /         |
//                  |    5  8   |     | 14        |
//                  |-----------|     |-----------|
//                   Leftsubtree-1      Rightsubtree-1

// Now going to Leftsubtree-1 ::::
//
//                          4 -------->Root         ==> {2}  { [5]  [8]  7 } 4
//                     /        |
//                 |---|    |-------|                ==> 
//                 | 2 |    |    7  |
//                 |---|    |   / | |
//          Leftsubtree-2   |  5  8 |
//                          |-------|
//                          Rightsubtree-2

// Now going to Leftsubtree-2 :::: (NOTE:: there is no Leftsubtree and Rightsubtree of Node 2 )
//
//                      2* ------------>Root    ==> 2
//                                              ==> 2

// Now going to Rightsubtree-2  :::::::
//
//                      7 --------->Root       ==> {5}  {8}  7
//                   /     |                   ==> 
//               |----|  |----|
//               | 5  |  | 8  |
//               |----|  |----|
//       Leftsubtree-3   Rightsubtree-3

// Now going to Leftsubtree-3  :::::: (NOTE:: there is no Leftsubtree and Rightsubtree of Node 5 )
//
//                      5* ------------>Root    ==> 5
//                                              ==> 2 5

// Now going to Rightsubtree-3 ::::::: (NOTE:: there is no Leftsubtree and Rightsubtree of Node 8 )
//
//                      8* ------------>Root    ==> 8
//                                              ==> 2 5 8

//After Leftsubtree-3 and Rightsubtree-3 , Root is printed Rightsubtree-2 
//                      7*--------->Root       ==> {5}  {8}  7
//                   /     |                   ==> 2 5 8 7
//               |----|  |----|
//               | 5  |  | 8  |
//               |----|  |----|
//       Leftsubtree-3   Rightsubtree-3


//After Leftsubtree-2 and Rightsubtree-2 , Root is printed Leftsubtree-1 
//
//                          4* -------->Root         ==> {2}  { [5]  [8]  7 } 4
//                     /        |
//                 |---|    |-------|                ==> 2 5 8 7 4
//                 | 2 |    |    7  |
//                 |---|    |   / | |
//          Leftsubtree-2   |  5  8 |
//                          |-------|
//                          Rightsubtree-2

//
// Now going to Rightsubtree-1 ::::
//
//
//                       11  ---------->Root     ==>   { [ 14 ] 15 } 11
//                         |                     ==> 
//                      |-------|
//                      |   15  |
//                      |  /    |
//                      | 14    |
//                      |-------|
//                   Rightsubtree-4

// Now going to Rightsubtree-4 ::::::
//
//                          15  ------>Root   ==>     { 14 } 15
//                         /                  ==> 
//                      |-----|
//                      | 14  |
//                      |-----|
//                     Leftsubtree-5

// Now going to Leftsubtree-5 ::::::: (NOTE:: there is no Leftsubtree and Rightsubtree of Node 14 )
//
//                      14* ------------>Root    ==> 14
//                                               ==> 2 5 8 7 4 14 

// After Leftsubtree-5 , Root is printed Rightsubtree-4 
//                          15* ------>Root   ==>     { 14 } 15
//                         /                  ==> 2 5 8 7 4 14 15
//                      |-----|
//                      | 14  |
//                      |-----|
//                     Leftsubtree-5
// 
// After Rightsubtree-4 , Root is printed Rightsubtree-1 
//                       11* ---------->Root     ==>  { [ 14 ] 15 } 11
//                         |                     ==> 2 5 8 7 4 14 15 11
//                      |-------|
//                      |   15  |
//                      |  /    |
//                      | 14    |
//                      |-------|
//                   Rightsubtree-4

//After Leftsubtree-1 and Rightsubtree-1 , Root is printed 

// 
//                               9*  ----------->     Root             ==>  { [2]  [  [5]  [8] 7 ] 4 }   { [  [ 14 ]  15] 11} 9
//                             /         |
//                  |-----------|     |-----------|                    ==> 2 5 8 7 4 14 15 11 9
//                  |    4      |     |  11       |
//                  |   /  |    |     |  |        |
//                  |  2   7    |     | 15        |
//                  |     / |   |     | /         |
//                  |    5  8   |     | 14        |
//                  |-----------|     |-----------|
//                   Leftsubtree-1      Rightsubtree-1


// #########################################################################################################################################################################

//******InOrder Traversal ************
//  Leftsubtree---->Root---->Rightsubtree
//
//                         9                ==> [  [2] 4  [  [5] 7 [8] ] ] 9  [11 [  [ 14 ] 15 ] ]
//                       /    |             ==> 2 4 5 7 8 9 11 14 15
//                      4     11
//                    /  |      |
//                   2   7     15
//                      / |    /
//                     5  8   14
//

// Inorder Traversal function print Root Node
//                               9  ----------->     Root             ==> {  [2] 4  [  [5] 7 [8] ] } 9  {11 [  [ 14 ] 15 ] }
//                             /         |
//                  |-----------|     |-----------|                   ==> 
//                  |    4      |     |  11       |
//                  |   /  |    |     |  |        |
//                  |  2   7    |     | 15        |
//                  |     / |   |     | /         |
//                  |    5  8   |     | 14        |
//                  |-----------|     |-----------|
//                   Leftsubtree-1      Rightsubtree-1

// Now going to Leftsubtree-1 ::::
//
//                          4  -------->Root         ==>  {2} 4  {  [5] 7  [8] }
//                     /        |
//                 |---|    |-------|                ==> 
//                 | 2 |    |    7  |
//                 |---|    |   / | |
//          Leftsubtree-2   |  5  8 |
//                          |-------|
//                          Rightsubtree-2

// Now going to Leftsubtree-2 :::: (NOTE:: there is no Leftsubtree and Rightsubtree of Node 2 )
//
//                      2* ------------>Root    ==> 2
//                                              ==> 2

// 
//After Leftsubtree-2 and before Rightsubtree-2 , Root is printed 
// 
//                          4* -------->Root         ==> {2} 4  {  [5] 7 [8] }
//                     /        |
//                 |---|    |-------|                ==> 2 4
//                 | 2 |    |    7  |
//                 |---|    |   / | |
//          Leftsubtree-2   |  5  8 |
//                          |-------|
//                          Rightsubtree-2

// Now going to Rightsubtree-2  :::::::
//
//                      7*--------->Root       ==>  {5} 7  {8}
//                   /     |                   ==> 2 4
//               |----|  |----|
//               | 5  |  | 8  |
//               |----|  |----|
//       Leftsubtree-3   Rightsubtree-3

// Now going to Leftsubtree-3  :::::: (NOTE:: there is no Leftsubtree and Rightsubtree of Node 5 )
//
//                      5* ------------>Root    ==> 5
//                                              ==> 2 4 5

//
//After Leftsubtree-3 and before Rightsubtree-3 , Root is printed 
// 
//                      7*--------->Root       ==>  {5} 7  {8}
//                   /     |                   ==> 2 4 5 7
//               |----|  |----|
//               | 5  |  | 8  |
//               |----|  |----|
//       Leftsubtree-3   Rightsubtree-3

// Now going to Rightsubtree-3 ::::::: (NOTE:: there is no Leftsubtree and Rightsubtree of Node 8 )
//
//                      8* ------------>Root    ==> 8
//                                              ==> 2 4 5 7 8

//After Leftsubtree-1 and before Rightsubtree-1 , Root is printed  
// 
//                               9*  ----------->     Root             ==> {  [2] 4  [  [5] 7 [8] ] } 9  {11 [  [ 14 ] 15 ] }
//                             /         |
//                  |-----------|     |-----------|                   ==> 2 4 5 7 8 9
//                  |    4      |     |  11       |
//                  |   /  |    |     |  |        |
//                  |  2   7    |     | 15        |
//                  |     / |   |     | /         |
//                  |    5  8   |     | 14        |
//                  |-----------|     |-----------|
//                   Leftsubtree-1      Rightsubtree-1

//
// Now going to Rightsubtree-1 ::::(NOTE :: Leftsubtree-4 is not there that's why printing Root directly)
//
//After Leftsubtree-4 and before Rightsubtree-4 , Root is printed 
// 
//                       11* ---------->Root     ==>  11 { [ 14 ] 15 }
//                         |                     ==> 2 4 5 7 8 9 11
//                      |-------|
//                      |   15  |
//                      |  /    |
//                      | 14    |
//                      |-------|
//                   Rightsubtree-4

// Now going to Rightsubtree-4 ::::::
//
//                          15* ------>Root   ==>     { 14 } 15
//                         /                  ==> 2 4 5 7 8 9 11 
//                      |-----|
//                      | 14  |
//                      |-----|
//                     Leftsubtree-5

// Now going to Leftsubtree-5 ::::::: (NOTE:: there is no Leftsubtree and Rightsubtree of Node 14 )
//
//                      14* ------------>Root    ==> 14
//                                               ==> 2 4 5 7 8 9 11 14
// 
// 
//After Leftsubtree-5 and before Rightsubtree-5 , Root is printed ::: (NOTE :: Leftsubtree-4 is not there that's why printing Root directly) 
// 
//                          15* ------>Root   ==>    { 14 } 15
//                         /                  ==> 2 4 5 7 8 9 11 14 15 
//                      |-----|
//                      | 14  |
//                      |-----|
//                     Leftsubtree-5
// 
// 








// DSA
// C++
// GIT
//
//
