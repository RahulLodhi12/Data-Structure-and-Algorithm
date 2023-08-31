#include<bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
int func1(vector<vector<int>>& mat, int n){
    vector<int> out(n,0);
    vector<int> in(n,0);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j] == 1){
                out[i]++;
                in[j]++;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(out[i]==0 && in[i]==n-1){
            return i;
        }
    }

    return -1;
}


// Approach 2: Optimal Solution(Using Stack)
int func2(vector<vector<int>>& mat, int n){
    //step 1: push every element into stack.
    stack<int> st;
    for(int i=0;i<n;i++){
        st.push(i);
    }

    //step 2: pop row and col from stack
    while(st.size()>1){
        int row = st.top();
        st.pop();
        int col = st.top();
        st.pop();

        if(mat[row][col]==1){ // row know col means that col may or may not be celeb.
            st.push(col);
        }
        else{
            st.push(row);
        }
    }

    //step 3: only element left in stack may or may not be celeb., then verify it.
    int x = st.top();
    st.pop();

    //celeb. -> row -> all 0's except diagonal elements
    for(int i=0;i<n;i++){
        if(i==x) continue;
        if(mat[x][i]==1){
            return -1;
        }
    }

    //celeb. -> col -> all 1's except diagonal elements
    for(int i=0;i<n;i++){
        if(i==x) continue;
        if(mat[i][x]==0){
            return -1;
        }
    }
    
    return x;
}

int main(){
    vector<vector<int>> mat = {{0, 1, 1, 0},{0, 0, 0, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    int n = mat.size();

    // cout<<func1(mat,n)<<endl;

    cout<<func2(mat,n)<<endl;
}