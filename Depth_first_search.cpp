#include<iostream>
using namespace std;

void DSF(int i){
    int j;
    cout<<i<<endl;
    // DFS Implementation 
    int visited[7]={0,0,0,0,0,0,0};
    int A[7][7]={
            {0,1,1,1,0,0,0},
            {1,0,1,0,0,0,0},
            {1,1,0,1,1,0,0},
            {1,0,1,0,1,0,0},
            {0,0,1,1,0,1,1},
            {0,0,0,0,1,0,0},
            {0,0,0,0,1,0,0}
    };
    visited[i]=1;
    // stack operation is done by C program
    for(int j;j<7;j++){
    if(A[i][j]==1&& !visited[j]){
        DSF(j);
    }

    }
}

int main(){
    DSF(0);
    return 0;
}