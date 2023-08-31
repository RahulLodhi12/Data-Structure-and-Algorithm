#include<bits/stdc++.h>
using namespace std;

void markRow(vector<vector<int>>& matrix, int i, int m){
    for(int k=0;k<m;k++){
        if(matrix[i][k]!=0){
            matrix[i][k] = -1;
        }
    }
}
void markCol(vector<vector<int>>& matrix, int n, int j){
    for(int k=0;k<n;k++){
        if(matrix[k][j]!=0){
            matrix[k][j] = -1;
        }
    }
}

// Approach 1: Brute Force
void func1(vector<vector<int>>& matrix, int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                markRow(matrix, i, m);
                markCol(matrix, n, j);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==-1){
                matrix[i][j]=0;
            }
        }
    }
}


// Approach 2: Better Solution
void func2(vector<vector<int>>& matrix, int n, int m){
    vector<int> col(m,0);
    vector<int> row(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i]==1 || col[j]==1){
                matrix[i][j]=0;
            }
        }
    }
}

int main(){
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    int n = matrix.size(); // row
    int m = matrix[0].size(); // col

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    // func1(matrix,n,m);
    
    func2(matrix,n,m);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}