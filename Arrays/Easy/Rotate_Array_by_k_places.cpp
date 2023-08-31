#include<bits/stdc++.h>
using namespace std;

// Approach 1 : Brute Force (Temp array)
void rotateRight1(vector<int> &arr, int n, int k){
    k = k % n;
    int temp[k];

    for(int i=n-k;i<n;i++){
        temp[i-(n-k)] = arr[i];
    }

    for (int i=n-k-1; i>=0; i--){ // from back direction
        arr[i + k] = arr[i];
    }

    for(int i=0;i<k;i++){
        arr[i] = temp[i];
    }
}

void rotateLeft1(vector<int>& arr, int n, int k){
    k = k % n; // Get the effective number of rotations
    int temp[k];

    for(int i=0;i<k;i++){
        temp[i] = arr[i];
    }

    for (int i = 0; i < n - k; i++){
        arr[i] = arr[i + k];
    }
    
    for (int i = n - k; i < n; i++){
        arr[i] = temp[i - n + k];
    }
}


// Approach 2 : Reversal Algorithm
void reverse(vector<int>& arr, int s, int e){
    while(s<=e){
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
}

void rotateRight2(vector<int>& arr, int n, int k){
    reverse(arr,0,n-k-1);
    reverse(arr,n-k,n-1);
    reverse(arr,0,n-1);

}

void rotateLeft2(vector<int>& arr, int n, int k){
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
    reverse(arr,0,n-1);
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    int n = arr.size();
    int k=2;

    // rotateRight1(arr, n, k);
    // rotateLeft1(arr,n,k);

    // rotateRight2(arr,n,k);
    rotateLeft2(arr,n,k);

    cout<<"After Rotation: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}