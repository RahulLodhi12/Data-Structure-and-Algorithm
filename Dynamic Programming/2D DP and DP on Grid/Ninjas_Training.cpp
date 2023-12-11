#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using Recursion
int solve(int day, int act, vector<vector<int>>& points, int n){
    //base cases
    if(day==0){
        int maxSum = (int)-1e9;
        for(int i=0;i<=2;i++){
            if(i!=act) maxSum = max(maxSum,points[0][i]);
        }
        return maxSum;
    }

    int maxSum = (int)-1e9;
    for(int i=0;i<=2;i++){ //activity
        if(i!=act) maxSum = max(maxSum, points[day][i] + solve(day-1,i,points,n));
    }

    return maxSum;
}


// Approach 2: Using DP
// Torromow

int ninjaTraining(int n, vector<vector<int>>& points){
    int ans = solve(n-1,3,points,n);
    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<vector<int>> points(n);

    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            int t;
            cin>>t;
            points[i].push_back(t);
        }
    }

    cout<<ninjaTraining(n,points);

    // cout<<"print: "<<endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<3;j++){
    //         cout<<points[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}