#include<bits/stdc++.h>
using namespace std;

string func(string str){
    unordered_map <char,int> cnt;
    queue<int> q;
    string ans = "";
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        cnt[ch]++;
        q.push(ch);

        while(q.empty()==0){ // assume: q.front -> Non reapeating -> add to "ans" string.
            if(cnt[q.front()]>1){ // repeated
                q.pop();
            }
            else{ // non-repeated
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty()==1){
            ans.push_back('#');
        }
    }

    return ans;
}

int main(){
    string str;
    cin>>str;

    cout<<func(str)<<endl;
}