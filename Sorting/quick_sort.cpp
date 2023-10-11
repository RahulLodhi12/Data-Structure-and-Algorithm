#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int p = low;
    int q = high;

    int i = low;
    while(arr[p]<pivot && i<=high){
        p++;
        i++;
    }

    int j = high;
    while(arr[q]>pivot && j>=low){
        q--;
        j--;
    }

    if(p>=q){
        swap(arr[q],pivot);
    }
    else{
        swap(arr[p],arr[q]);
    }

    return q;
}

void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi = partition(arr,low,high);

        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    quickSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}