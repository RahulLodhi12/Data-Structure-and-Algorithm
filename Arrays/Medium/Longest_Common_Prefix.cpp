#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs){
    string ans="";

    sort(strs.begin(),strs.end());

    int n = strs.size();
    string first = strs[0], last = strs[n-1];

    for(int i=0;first[i] && last[i];i++){
        if(first[i]!=last[i]){ //no common
            return ans;
        }
        ans+=first[i]; //common
    }

    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<string> strs;

    for(int i=0;i<n;i++){
        string t;
        cin>>t;
        strs.push_back(t);
    }

    cout<<longestCommonPrefix(strs);
}