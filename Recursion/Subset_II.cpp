#include <bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
void func(int i, vector<int>& arr, vector<int>& ds, set<vector<int>>& res){
    //base case
    int n = arr.size();
    if(i==n){
        sort(ds.begin(), ds.end());
        res.insert(ds); //because res is a set, we use insert.
        return;
    }

    //pick
    ds.push_back(arr[i]);
    func(i+1,arr,ds,res);

    //not pick
    ds.pop_back();
    func(i+1,arr,ds,res);
}

vector<vector<int>> subsets(vector<int> & arr)
{
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    set<vector<int>> res;
    vector<int> ds;
    func(0,arr,ds,res);

    for (auto it = res.begin(); it != res.end(); it++) // put data from set into vector.
    {
        ans.push_back(*it);
    }
    return ans;
}
//Time Complexity: O( 2^n *(k log (x) ))
//Space Complexity:  O(2^n * k)

//------------------------------------------------------------------------------------------

//Approach 2: Optimal
void func2(int i, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    // base condn.
    ans.push_back(ds);

    // possible case
    for (int k = i; k < arr.size(); k++)
    {
        //not pick
        if (k != i && arr[k] == arr[k - 1]) continue; // not pick for 1st time/ to avoid duplicates.

        // pick
        ds.push_back(arr[k]);
        func2(k + 1, arr, ans, ds);
        ds.pop_back();
    }

    //not possible case
}

vector<vector<int>> subsets2(vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> ds;
    func2(0, arr, ans, ds);

    return ans;
}
//Time Complexity: O(2^n)
//Space Complexity: O(2^n * k)



int main(){
    vector<int> v{1,2,2};
    vector<vector<int>> ans = subsets(v);
    // vector<vector<int>> ans = subsets2(v);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    
}