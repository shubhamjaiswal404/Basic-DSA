#include<iostream>
using namespace std;

struct queue{
    int size;
    int f;
    int r;
    int* arr;
};

class Graph{
    public:
    int isEmpty(queue*q);
    int isFull(queue*q);
    void equeue(queue *q,int value);
    int dequeue (queue*q);
    void BFS_traversal(queue &q);



};

int Graph::isEmpty(queue*q){
    if(q->r==q->f){
        return 1;
    }

    return 0;
}

int Graph::isFull(queue*q){
    if(q->r==q->size-1){
        return 1;
    }

    return 0;
}

void Graph::equeue(queue *q,int value){
    if(isFull(q)){
        cout<<"this Queue is Full "<<endl;
    }
    else{
        q->r++;
        q->arr[q->r]=value;
        // cout<<"Enqueued element "<<value<<endl;
    }
}

int Graph::dequeue (queue*q){
    int a=-1;
    if(isEmpty(q)){
        cout<<"This Queue is Empty "<<endl;
    }
    else{
        q->f++;
        a=q->arr[q->f];
    }

    return a;
}

void Graph::BFS_traversal(queue &q){
    // BFS Implementation 
    int u;
    int i=0;
    int node;
    int visited[7]={0,0,0,0,0,0,0};
    int a[7][7]={
            {0,1,1,1,0,0,0},
            {1,0,1,0,0,0,0},
            {1,1,0,1,1,0,0},
            {1,0,1,0,1,0,0},
            {0,0,1,1,0,1,1},
            {0,0,0,0,1,0,0},
            {0,0,0,0,1,0,0}
    };

    cout<<i<<endl;
    visited[i]=1;
    // enqueue(&q,i);  //Enqueue i for exploration

    while(isEmpty(&q)){
        int node=dequeue(&q);
        for(int j=0;j<7;j++){
            if(a[node][j]==1 && visited [j]==0){
                cout<<j<<endl;
                visited[j]=1;
                // enqueue(&q,j);
            }
        }
    }
}

int main(){
    
    // Initiallizing Queue (Array Implementation)
     queue q;
     q.size=400;
     q.f=q.r=0;
     q.arr = new int [q.size];

     Graph Object;
    Object.BFS_traversal(q);

    
    return 0;
}