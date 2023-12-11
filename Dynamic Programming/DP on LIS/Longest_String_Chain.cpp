#include<bits/stdc++.h>
using namespace std;

bool checkPredecessor(string s1, string s2){
    int n = s1.length();
    int m = s2.length();

    if(m-n>1) return false;

    int i=0;
    int j=0;
    while(i<n && j<m){
        if(s1[i]==s2[j]){
            i++;
            j++;
        }
        else{
            j++;
        }
    }

    if(i==n) return true;

    return false;
}

int solve(int i, int p, vector<string>& words){
    //base case
    if(i==words.size()) return 0;

    int take = 0;
    int skip = 0;
    if(p==-1 || checkPredecessor(words[p],words[i]))
        take = 1 + solve(i+1,i,words);
    
    skip = 0 + solve(i+1,p,words);

    return max(take,skip);
}

bool onLength(string w1, string w2){
    return w1.length() < w2.length();
}

int longestStrChain(vector<string>& words){
    //sorting(based on length)
    sort(words.begin(),words.end(),onLength);

    //lis
    int ans = solve(0,-1,words);
    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<string> words;

    for(int i=0;i<n;i++){
        string t;
        cin>>t;
        words.push_back(t);
    }

    cout<<longestStrChain(words);
}