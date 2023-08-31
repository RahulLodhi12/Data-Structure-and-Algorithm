#include<bits/stdc++.h>
using namespace std;

void powerSet(string s, vector<string>& ans){
    int n = s.length();
    for (int num=0; num<(1<<n);num++){
        string sub=""; //sub-string for subsets(ex. is "ab" or "ac" or "bc" or "abc")
        for(int i=0;i<n;i++){
            if(num&(1<<i)){
                sub+=s[i];
            }
        }
        if(sub.length()>0) // for all the test cases.
            ans.push_back(sub);
    }
}

int main(){
    string s = "abc";
    vector<string> ans;
    powerSet(s, ans);

    for(auto it:ans){
        cout<<it<<" ";
    }
}

// T.C: O(2^n * n)
// S.C: O(2^n * n)