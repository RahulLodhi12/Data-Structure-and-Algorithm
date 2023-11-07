//Delete middle element from array and array size reduced
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    
    char ch;
    cin>>ch;
    
    int n = s.length();
    vector<char> str(n); // consider vector in case of array.
    
    cout<<str.size()<<endl;
    
    for(int i=0;i<n;i++){
        str[i] = s[i];
    }
    
    for(int i=0;i<n;i++){
        auto it = find(str.begin(), str.end(),ch); // finding the position of the deleted element
        if(it != str.end()){
            str.erase(it); // erase that particular element from array(here. vector)
        }
    }
    
    cout<<str.size()<<endl; // print the reduced array size
    return 0;
}