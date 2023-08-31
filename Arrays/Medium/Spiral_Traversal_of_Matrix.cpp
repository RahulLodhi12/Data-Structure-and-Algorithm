#include<bits/stdc++.h>
using namespace std;

// Only one solution for this problem
vector<int> func1(vector<vector<int>>& matrix, int n, int m){
    vector<int> ans;
    int top=0, bottom = n-1, left=0, right = m-1;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){ // check is done because of for loop
            ans.push_back(matrix[top][i]);
        }
        top++;
        
        for(int i=top;i<=bottom;i++){ // check is done because of for loop
            ans.push_back(matrix[i][right]);
        }
        right--;

        if(top<=bottom){
            for(int i=right;i>=left;i--){ // check (left<=right) is done, but not the check (top<=bottom)
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if(left<=right){
            for(int i=bottom;i>=top;i--){ // check (top<=bottom) is done, but not the check (left<=right)
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> ans = func1(matrix,n,m);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}