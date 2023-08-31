#include<bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
void moveZeros1(vector<int>& arr){
    int n=arr.size();
    vector<int> temp={0};

    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            temp[j]=arr[i];
            j++;
        }
    }
    while(j<n){
        temp[j]=0;
        j++;
    }

    for(int i=0;i<n;i++){
        cout<<temp[i]<<" ";
    }
}


// Approach 2: Two pointer
void moveZeros2(vector<int>& arr){
    int n = arr.size();
    // i -> zero and j -> non-zero
    int i=-1;
    for(int p=0;p<n;p++){
        if(arr[p]==0){
            i=p; // point to zero
            break;
        }
    }

    int j=i+1;
    while(j<n){
        if(arr[i]==0 && arr[j]!=0){
            swap(arr[i],arr[j]);
            i++;
        }
        j++;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    vector<int> arr={1 ,0 ,2 ,3 ,0 ,4 ,0 ,1};

    // moveZeros1(arr);

    moveZeros2(arr);
}