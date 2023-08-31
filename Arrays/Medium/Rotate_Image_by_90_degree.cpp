#include<bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
vector<vector<int>> func1(vector<vector<int>>& matrix, int n, int m){
    vector<vector<int>> temp = matrix;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            temp[j][(n-1)-i] = matrix[i][j];
        }
    }
    return temp;
}

// Approach 2: Optimal Solution
vector<vector<int>> func2(vector<vector<int>>& matrix, int n, int m){
    // transpose
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    
    // swap cols
    for(int i=0;i<n;i++){
        for(int j=0;j<m/2;j++){
            swap(matrix[i][j],matrix[i][(n-1)-j]);
        }
    }

    return matrix;
}


int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    int n = matrix.size(); // row
    int m = matrix[0].size(); // col

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    // vector<vector<int>> ans = func1(matrix,n,m);

    vector<vector<int>> ans = func2(matrix,n,m);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}