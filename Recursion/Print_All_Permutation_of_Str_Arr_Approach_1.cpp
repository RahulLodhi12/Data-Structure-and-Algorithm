#include <bits/stdc++.h>
using namespace std;

void func(vector<int> &ds, int freq[], vector<int> &arr, vector<vector<int>> &ans)
{
    // base case
    if (ds.size() == arr.size())
    {
        ans.push_back(ds);
        return;
    }

    // possible case
    for (int i = 0; i < arr.size(); i++)
    {
        if (freq[i]==0)
        {
            ds.push_back(arr[i]);
            freq[i] = 1;
            func(ds, freq, arr, ans);
            freq[i] = 0;
            ds.pop_back();
        }
    }

    // not possible case
}

vector<vector<int>> allPermutation(vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> ds;
    int n = arr.size();
    int freq[n];
    for (int i = 0; i < arr.size(); i++)
    {
        freq[i]=0;
    }
    

    func(ds, freq, arr, ans);

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