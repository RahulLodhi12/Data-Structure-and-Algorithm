#include<bits/stdc++.h>
using namespace std;


vector<int> nextSmallerElement(vector<int>& heights, int n){
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

vector<int> prevSmallerElement(vector<int>& heights, int n){
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

int largestAreainHistogram(vector<int>& heights,int m){
    int maxArea = 0;
    vector<int> next = nextSmallerElement(heights,m); // stores indexes
    vector<int> prev = prevSmallerElement(heights,m); // stores indexes

    for(int i=0;i<m;i++){
        int l = heights[i];
        int b = next[i] - prev[i] - 1;
        int area = l*b;
        maxArea = max(area,maxArea);
    }

    return maxArea;
}

// Approach: Using Largest Reactangle area in Histogram;
int solve(vector<vector<int>>& M, int n, int m){
    int area = largestAreainHistogram(M[0],m);

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(M[i][j]!=0){
                M[i][j] += M[i-1][j];
            }
            else{
                M[i][j]=0;
            }
        }
        area = max(area,largestAreainHistogram(M[i],m));
    }

    return area;
}


int main(){
    vector<vector<int>> M = {{0, 1, 1, 0},{1, 1, 1, 1},{1, 1, 1, 1},{1, 1, 0, 0}};
    int n = M.size();
    int m = M[0].size();

    cout<<solve(M,n,m);
}