#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0;i<n-1;i++){ // total passes
        int mini = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[mini]){
                mini = j;
            }
        }

        if(mini != i){
            swap(arr[i],arr[mini]);
        }
    }
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    selectionSort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
