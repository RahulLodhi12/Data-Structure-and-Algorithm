#include<bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force : Not on my notebook
int func1(vector<int>& heights){
    int maxArea = INT_MIN;
    for(int i=0;i<heights.size();i++){
        int left = i;
        int right = i;
        
        while(heights[left]>=heights[i] && left>=0){ // jab tak badha element hai to left--;
            left--;
        }

        while(heights[right]>=heights[i] && right<heights.size()){ // jab tak badha element hai tp right++;
            right++;
        }
        
        int area = (right - left - 1)*heights[i];
        maxArea = max(area,maxArea);
    }
    return maxArea;
}



vector<int> nextSmallerElement(vector<int>& heights){
    int n = heights.size();
    vector<int> ans(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        int curr = heights[i];
        while(st.empty()==false && heights[st.top()]>=curr){
            st.pop();
        }
        if(st.empty()){
            ans[i] = n;
        } 
        else{
            ans[i] = st.top();
        }  
        st.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int>& heights){
    int n = heights.size();
    vector<int> ans(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        int curr = heights[i];
        while(st.empty()==false && heights[st.top()]>=curr){
            st.pop();
        }
        if(st.empty()){
            ans[i] = -1;
        } 
        else{
            ans[i] = st.top();
        }  
        st.push(i);
    }
    return ans;
}

// Approach 2: Optimal Solution(Using Stack)
int func2(vector<int>& heights){
    int maxArea = 0;
    vector<int> next = nextSmallerElement(heights); // stores indexes
    vector<int> prev = prevSmallerElement(heights); // stores indexes

    for(int i=0;i<heights.size();i++){
        int l = heights[i];
        int b = next[i] - prev[i] - 1;
        int area = l*b;
        maxArea = max(area,maxArea);
    }

    return maxArea;
}

int main(){
    vector<int> heights = {6, 2, 5, 4, 5, 1, 6};

    cout<<func1(heights);

    // cout<<func2(heights);

    
}