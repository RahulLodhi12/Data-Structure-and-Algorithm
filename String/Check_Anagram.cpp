#include<bits/stdc++.h>
using namespace std;

bool checkAnagram(string s1, string s2){

    if(s1.length() != s2.length()){
        return false;
    }

    int count1[256] = {0};
    int count2[256] = {0};

    for(int i=0;i<s1.length();i++){
        count1[s1[i]]++;
    }

    for(int i=0;i<s2.length();i++){
        count2[s2[i]]++;
    }

    for(int i=0;i<256;i++){
        if(count1[i] != count2[i]){
            return false;
        }
    }
    return true;
}

int main(){
    string s1;
    getline(cin,s1);

    string s2;
    getline(cin,s2);

    cout<<checkAnagram(s1,s2);
}
