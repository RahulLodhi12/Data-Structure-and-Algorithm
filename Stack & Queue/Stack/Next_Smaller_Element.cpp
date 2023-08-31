#include<bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
vector<int> func1(vector<int>& arr){
    vector<int> ans;
    for(int i=0;i<arr.size();i++){
        int next = -1;
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<arr[i]){
                next = arr[j];
                break;
            }
        }
        ans.push_back(next);
    }
    return ans;
}


// Approach 2: Optimal Solution(Using Stack)
vector<int> func2(vector<int>& arr){
    vector<int> ans(arr.size());
    stack<int> st;
    for(int i=arr.size()-1;i>=0;i--){
        int curr = arr[i];
        if(st.empty()==false && st.top()<curr){
            ans[i] = st.top();
            st.push(curr);
        }
        else{
            while(st.empty()==false && st.top()>=curr){
                st.pop();
            }
            if(st.empty()){
                ans[i] = -1; // for putting -1 in ans vector
            } 
            else{
                ans[i] = st.top();
            }  
            st.push(curr);
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {13,7,6,12};

    // vector<int> ans = func1(arr);

    vector<int> ans = func2(arr);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}