#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using Recursion
int solve(int i, int j, vector<vector<int>>& matrix,int m,int n){
    //base cases
    if(j<0 || j>=n)  return int(1e9); //out of bound cases
    if(i==m-1) return matrix[i][j];

    int down = matrix[i][j] + solve(i+1,j,matrix,m,n);
    int leftDia = matrix[i][j] + solve(i+1,j-1,matrix,m,n);
    int rightDia = matrix[i][j] + solve(i+1,j+1,matrix,m,n);

    return min(down,min(leftDia,rightDia));
}


// Approach 2: Using DP
int dp[101][101];
int sollve(int i, int j, vector<vector<int>>& matrix,int m,int n){
    //base cases
    if(j<0 || j>=n)  return int(1e9); //out of bound cases
    if(i==m-1) return matrix[i][j];

    //provide
    if(dp[i][j] != -1) return dp[i][j];

    int down = matrix[i][j] + sollve(i+1,j,matrix,m,n);
    int leftDia = matrix[i][j] + sollve(i+1,j-1,matrix,m,n);
    int rightDia = matrix[i][j] + sollve(i+1,j+1,matrix,m,n);

    return dp[i][j] = min(down,min(leftDia,rightDia));
}


// Approach 3: Using Tabulation
int soolve(vector<vector<int>>& mat, int m, int n){
    //2-D dp array
    vector<vector<int>> dp(m, vector<int> (n,0));

    //populate first row
    for(int col=0;col<n;col++) dp[0][col] = mat[0][col];

    //after first row
    for(int row=1;row<m;row++){
        for(int col=0;col<n;col++){
            int leftDia = (int)1e9;
            int rightDia = (int)1e9;

            if(col-1>=0) leftDia = dp[row-1][col-1];
            if(col+1<n) rightDia = dp[row-1][col+1];

            dp[row][col] = mat[row][col] + min({dp[row-1][col],leftDia,rightDia});
        }
    }

    //find min among last row
    int ans = (int)1e9;
    for(int col=0;col<n;col++) ans = min(ans, dp[m-1][col]);

    return ans;
}

int minFallingPathSum(vector<vector<int>>& matrix){
    int minSum = (int)1e9;
    int m = matrix.size();
    int n = matrix[0].size();

    //row = 0;
    // for(int col=0;col<n;col++){
    //     minSum = min(minSum,solve(0,col,matrix,m,n));
    // }
    // return minSum;

    memset(dp,-1,sizeof(dp));
    for(int col=0;col<n;col++){
        minSum = min(minSum,sollve(0,col,matrix,m,n));
    }
    return minSum;
}

int main(){
    int m,n;
    cin>>m>>n;

    vector<vector<int>> matrix(m);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int t;
            cin>>t;
            matrix[i].push_back(t);
        }
    }

    // cout<<minFallingPathSum(matrix);

    cout<<soolve(matrix,m,n);
}