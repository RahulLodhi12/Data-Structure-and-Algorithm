#include<bits/stdc++.h>
using namespace std;

// Approach 1
void app1(int n, int arr[]){
    int first=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>first){
            first = arr[i];
        }
    }

    int second=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>second && arr[i]<first){
            second = arr[i];
        }
    }

    int third=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>third && arr[i]<second){
            third = arr[i];
        }
    }

    cout<<third<<endl;
}

//Approach 2
void app2(int n, int arr[]){
    int first = INT_MIN, second = INT_MIN, third = INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>first){
            third = second;
            second = first;
            first = arr[i];
        }
        else if(arr[i]>second){
            third = second;
            second = arr[i];
        }
        else if(arr[i]>third){
            third = arr[i];
        }
    }

    cout<<third<<endl;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // app1(n,arr);

    app2(n,arr);

}