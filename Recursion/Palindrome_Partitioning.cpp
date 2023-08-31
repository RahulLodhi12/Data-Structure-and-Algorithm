#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int st, int e){
    while(st<=e){
        if(s[st++]!=s[e--]){
            return false;
        }
    }
    return true;
}

void func(int ind, vector<vector<string>>& ans, string s, vector<string>& ds){
    // base case
    if(ind==s.size()){
        ans.push_back(ds);
        return;
    }


    // possible case
    for(int i=ind;i<s.size();i++){
        if(isPalindrome(s,ind,i)){
            ds.push_back(s.substr(ind,i-ind+1));
            func(i+1,ans,s,ds);
            ds.pop_back();
        }
    }

    // not possible case
}

vector<vector<string>> partition(string s){
    vector<vector<string>> ans;
    vector<string> ds;

    func(0,ans,s,ds);

    return ans;
}

int main(){
    string s="aabb";

    vector<vector<string>> ans = partition(s);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}