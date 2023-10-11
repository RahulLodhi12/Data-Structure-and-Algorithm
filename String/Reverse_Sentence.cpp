#include<bits/stdc++.h>
using namespace std;

void reverseSen(string &s){
    int left = 0;
    int right = s.size()-1;
    // cout<<right<<endl;

    string temp = ""; //temp. string
    string ans = "";

    while(left<=right){
        char ch = s[left];
        if(ch != ' '){
            temp += ch;
        }
        else if(ch == ' '){
            if(ans != "") ans = temp + " " + ans;
            else ans = temp;
            temp = "";
        }
        left++;
    }

    if(temp != ""){
        ans = temp + " " + ans;
    }

    cout<<ans;
}

int main(){
    string s;
    getline(cin,s);
    // cout<<s;

    reverseSen(s);
}