#include<bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force [Doesn't work on duplicates]
void func1(vector<int>& arr){
    sort(arr.begin(), arr.end());
    cout<<"Second Smallest: "<<arr[1]<<endl;
    cout<<"Second Largest: "<<arr[arr.size()-2]<<endl;
}


// Appraoch 2: Better Solution
void func2(vector<int>& arr){
    int small = INT_MAX, secSmall = INT_MAX;
    int large = INT_MIN, secLarge = INT_MIN;

    for(int i=0;i<arr.size();i++){
        if(arr[i]<small){
            small = arr[i];
        }

        if(arr[i]>large){
            large = arr[i];
        }
    }
    cout<<"Smallest: "<<small<<endl;
    cout<<"Largest: "<<large<<endl;

    for(int i=0;i<arr.size();i++){
        if(arr[i]<secSmall && arr[i]!=small){
            secSmall = arr[i];
        }
        if(arr[i]>secLarge && arr[i]!=large){
            secLarge = arr[i];
        }
    }
    cout<<"Second Smallest: "<<secSmall<<endl;
    cout<<"Second Largest: "<<secLarge<<endl;
}


// Approach 3: Best Solution
void func3(vector<int>& arr){
    // For Second Small
    int small = arr[0];
    int secSmall = INT_MAX;
    for(int i=1;i<arr.size();i++){
        if(arr[i]<small){
            secSmall = small;
            small = arr[i];
        }
        else if(arr[i]<secSmall && arr[i]!=small){
            secSmall = arr[i];
        }
    }
    cout<<"Second Smallest: "<<secSmall<<endl;

    // For Second Large
    int large = arr[0];
    int secLarge = INT_MIN;
    for(int i=1;i<arr.size();i++){
        if(arr[i]>large){
            secLarge = large;
            large = arr[i];
        }
        else if(arr[i]>secLarge && arr[i]!=large){
            secLarge = arr[i];
        }
    }
    cout<<"Second Largest: "<<secLarge<<endl;
}

int main(){
    vector<int> arr = {12, 35, 1, 10, 34, 1};

    // func1(arr);

    // func2(arr);

    func3(arr);
}