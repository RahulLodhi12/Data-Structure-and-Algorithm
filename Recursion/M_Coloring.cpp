#include<bits/stdc++.h>
using namespace std;

bool adj(int node, int color[], bool graph[101][101], int N, int col){
    for(int k=0;k<N;k++){
        if(k!=node && graph[k][node]==1 && color[k]==col){
            return false;
        }
    }
    return true;
}

bool func(int node, int color[], int M, int N, bool graph[101][101]){
    // base case
    if(node==N){ // int node is used as a pointer.
        return true;
    }

    // possible case
    for(int col=1;col<=M;col++){
        if(adj(node,color,graph,N,col)){
            color[node]=col; //color it!
            if(func(node+1,color,M,N,graph)==true) return true;
            color[node]=0; //erase the color.
        }
    }

    // not possible case
    return false;
}

bool graphColoring(bool graph[101][101], int M, int N){

    int color[N]={0}; // all nodes(4 nodes) are colored are 0 initially.
    if(func(0,color,M,N,graph)) return true;

    return false;
}

int main(){
    int N=4;
    int M=3;

    bool graph[101][101];
    memset(graph, false, sizeof graph);

    // Edges are (0, 1), (1, 2), (2, 3), (3, 0), (0, 2)
    graph[0][1] = 1; graph[1][0] = 1;
    graph[1][2] = 1; graph[2][1] = 1;
    graph[2][3] = 1; graph[3][2] = 1;
    graph[3][0] = 1; graph[0][3] = 1;
    graph[0][2] = 1; graph[2][0] = 1;

    cout<<graphColoring(graph,M,N)<<endl;
}