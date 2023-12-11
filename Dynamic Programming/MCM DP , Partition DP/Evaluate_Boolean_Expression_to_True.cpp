#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
//Approach 1: Using Recursion
long long solve(int i, int j, string& exp, bool TF){
    //base cases
    if(i>j) return 0; //totalWays are zero.
    if(i==j){
        if(TF==true){ //true
            if(exp[i]=='T') return 1;
            else return 0;
        }
        else{ //false
            if(exp[i]=='F') return 1;
            else return 0;
        }
    }


    long long totalWays=0;
    for(int k=i+1;k<=j-1;k+=2){
        long long lT = solve(i,k-1,exp,true);
        long long rT = solve(k+1,j,exp,true);
        long long lF = solve(i,k-1,exp,false);
        long long rF = solve(k+1,j,exp,false);

        //handle operator
        

        // totalWays = left*right;
        if(exp[k] == '&'){
            if(TF==true){
                totalWays += (lT*rT)%mod;
            }
            else{
                totalWays += ((lT*rF)%mod + (lF*rT)%mod + (lF*rF)%mod)%mod;
            }
        }
        else if(exp[k] == '|'){
            if(TF==true){
                totalWays += ((lT*rT)%mod + (lT*rF)%mod + (lF*rT)%mod)%mod;
            }
            else{
                totalWays += (lF*rF)%mod;
            }
        }
        else if(exp[k] == '^'){
            if(TF==true){
                totalWays += ((lT*rF)%mod + (lF*rT)%mod)%mod;
            }
            else{
                totalWays += ((lT*rT)%mod + (lF*rF)%mod)%mod;
            }
        }
    }

    return totalWays%mod;
}

int evaluateExp(string& exp){
    // cout<<exp;
    int n = exp.length();
    // cout<<n;
    return solve(0,n-1,exp,true);
}

int main(){
    string exp;
    getline(cin,exp);

    cout<<evaluateExp(exp);
}