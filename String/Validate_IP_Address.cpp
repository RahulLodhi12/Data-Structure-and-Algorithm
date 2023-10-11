#include<bits/stdc++.h>
using namespace std;

bool valid(string s){
    int cntDigit = 0;
    int cntDot = 0;

    for(int i=0;i<s.length();i++){
        if(s[i]=='.') cntDot++;
    }

    if(cntDot != 3) return false;

    unordered_set<string> sett;

    for(int i=0;i<256;i++){
        sett.insert(to_string(i));
    }

    string temp="";
    for(int i=0;i<s.length();i++){
        if(s[i] != '.'){
            temp += s[i];
        }
        else{
            if(sett.find(temp) != sett.end()){ //found it
                cntDigit++;
                temp="";
            }
        }
    }

    if(sett.find(temp) != sett.end()){ //last digit
        cntDigit++;
    }

    if(cntDigit == 4) return true;

    return false;
}

int main(){
    string s;
    getline(cin,s);

    cout<<valid(s);
}