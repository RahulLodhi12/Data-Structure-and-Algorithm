#include<bits/stdc++.h>
using namespace std;

void func(int ind, vector<int>& arr, vector<vector<int>>& ans){
    // base case
    if(ind==arr.size()){
        ans.push_back(arr);
        return;
    }

    // possible case
    for(int i=ind;i<arr.size();i++){
        swap(arr[ind],arr[i]);
        func(ind+1,arr,ans);
        swap(arr[ind],arr[i]);
    }

    // not possible case
}

vector<vector<int>> allPermutation(vector<int>& arr){
    vector<vector<int>> ans;
    int n = arr.size();
    func(0,arr,ans);

    return ans;
}

int main()
{
    vector<int> v{1, 2, 3};

    vector<vector<int>> ans = allPermutation(v);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}