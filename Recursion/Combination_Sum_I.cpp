#include <bits/stdc++.h>
using namespace std;

void findComb(int i, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    // base condn.
    if (i == arr.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return; // don't push just return the flow.
    }
    // pick
    if (arr[i] <= target)
    {
        ds.push_back(arr[i]);
        findComb(i, target - arr[i], arr, ans, ds);
        ds.pop_back();
    }
    // not pick
    findComb(i + 1, target, arr, ans, ds);
}

vector<vector<int>> combinationSum(vector<int> &arr, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    findComb(0, target, arr, ans, ds);

    return ans;
}

int main()
{
    vector<int> v{2, 3, 6, 7};
    // cout<<"rahul";
    vector<vector<int>> fans = combinationSum(v, 7);
    for (int i = 0; i < fans.size(); i++)
    {
        for (int j = 0; j < fans[i].size(); j++)
            cout << fans[i][j] << " ";
        cout << endl;
    }
}
