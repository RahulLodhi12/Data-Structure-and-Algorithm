#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, int j, string s){
    
    while(i<j){
        if(s[i]!=s[j])
            return false;
        i++;
        j--;
    }

    return true;
}

//Approach 1: Using Recursion
int solve(int i, int j, string s){
    //base cases
    if(i>=j) return 0;
    if(isPalindrome(i,j,s)) return 0;


    int ans = INT_MAX;
    for(int k=i;k<=j-1;k++){
        int tempAns = 1 + solve(i,k,s) + solve(k+1,j,s);
        ans = min(ans,tempAns);
    }

    return ans;
}

int minPartition(string s){
    int n = s.length();
    int ans = solve(0,n-1,s);
    return ans;
}

int main(){
    string s;
    getline(cin,s);

    cout<<minPartition(s);

}