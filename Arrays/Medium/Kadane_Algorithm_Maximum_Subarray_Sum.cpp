#include<bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
int func1(vector<int>& arr, int n){
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum += arr[k];
            }
            if(sum>maxi){
                maxi = sum;
            }
        }
    }
    return maxi;
}

// Approach 2: Better Solution
int func2(vector<int>& arr, int n){
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum += arr[j];
            
            if(sum>maxi){
                maxi = sum;
            }
        }
    }
    return maxi;
}

// Approach 3: Optimal Solution
int func3(vector<int>& arr, int n){
    int maxi = INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++){
        // step 1
        sum += arr[i];

        // step 2
        if(sum>maxi){
            maxi = sum;
        }

        // step 3
        if(sum<0){
            sum=0;
        }
    }
    return maxi;
}


// Approach 3: Optimal Solution (Follow-up Question) -> Print subarray also.
int func4(vector<int>& arr, int n){
    int maxi = INT_MIN;
    int sum=0;
    int s=-1;
    int e=-1;
    for(int i=0;i<n;i++){
        if(sum==0) s=i; // changes

        // step 1
        sum += arr[i];

        // step 2
        if(sum>maxi){
            maxi = sum;

            e = i; // changes
        }

        // step 3
        if(sum<0){
            sum=0;
        }
    }

    //print
    for(int i=s;i<=e;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return maxi;
}

int main(){
    vector<int> arr={-2,-3,4,-1,-2,1,5,-3};
    int n=arr.size();

    // cout<<func1(arr,n);

    // cout<<func2(arr, n);

    // cout<<func3(arr,n);
    
    cout<<func4(arr,n);
}