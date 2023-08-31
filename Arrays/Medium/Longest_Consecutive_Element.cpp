// Ans. doesn't count the repeated elements
#include<bits/stdc++.h>
using namespace std;

// Linear Search function used in Approach 1: Brute Force
bool ls(vector<int>& arr, int n, int k){
    for(int i=0;i<n;i++){
        if(arr[i]==k){
            return true;
        }
    }
    return false;
}

// Approach 1: Brute Force
int func1(vector<int>& arr, int n){
    int longest=1;
    for(int i=0;i<n;i++){
        int x = arr[i];
        int cnt=1;
        while(ls(arr,n,++x)==true){
            cnt++;
        }
        if(cnt>longest){
            longest = cnt;
        }
    }
    return longest;
}

// Approach 2: Better Solution
int func2(vector<int>& arr, int n){
    sort(arr.begin(),arr.end());
    int longest=1;
    int prev=arr[0];
    int cnt=1;
    
    for(int i=1;i<n;i++){
        // step 1
        if(arr[i]==prev+1){ // This check handle the consecutive elements[1,2,3,4]
            cnt++;
        }
        // step 2
        else if(arr[i] != prev){ // This check handle the non-consecutive elements[4,100];
            cnt=1;               // important , NOTE: We don't mention condition of repeated element[1,1,1..2,2]
        }
        // step 3
        prev = arr[i];

        // step 4
        if(cnt>longest){
            longest=cnt;
        }
    }
    return longest;
}

// Approach 3: Optimal Solution
int func3(vector<int>& arr, int n){
    set<int> setTable;
    for(auto it: arr){ // O(N)
        setTable.insert(it);
    }

    int longest=1;
    // 7+3+4 = O(2N)
    for(auto it: setTable){ // 7
        if(setTable.count(it-1)==0){ //set.count(x) -> return 1 or 0 means x is present or not in setTable.
            int num = it; // starting no.
            int cnt=1;
            while(setTable.count(num+1)==1){ // 3+4
                cnt++;
                num = num+1;
            }
            if(cnt>longest){
                longest = cnt;
            }
        }
    }

    //T.C -> O(N)+O(2N) = O(3N)
    return longest;
}


int main(){
    vector<int> arr = {100,102,100,101,101,4,3,2,3,2,1,1,1,2};
    int n = arr.size();

    // cout<<func1(arr,n);

    cout<<func2(arr,n);

    // cout<<func3(arr,n);
}