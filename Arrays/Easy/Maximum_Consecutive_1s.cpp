#include<bits/stdc++.h>
using namespace std;

int maxConsecutive(vector<int>& arr){
    int cnt=0;
    int maxCnt=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==1){
            cnt++;
        }
        else{
            cnt=0;
        }
        if(cnt>maxCnt){
            maxCnt=cnt;
        }
    }
    return maxCnt;
}

int main(){
    vector<int> arr={1, 0, 1, 1, 0, 1};

    cout<<maxConsecutive(arr);
}