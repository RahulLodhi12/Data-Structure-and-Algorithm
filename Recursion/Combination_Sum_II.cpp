#include <bits/stdc++.h>
using namespace std;

void findComb(int i, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    // base condn.
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }

    // possible case
    for (int k = i; k < arr.size(); k++)
    {
        if (k != i && arr[k] == arr[k - 1])
            continue; // not pick to avoid duplicates.
        if (arr[k] > target)
            break;    // not pick, break because of sorted ordered array.

        // pick
        ds.push_back(arr[k]);
        findComb(k + 1, target - arr[k], arr, ans, ds);
        ds.pop_back();
    }


    //not possible case
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
    vector<int> v{10, 1, 2, 7, 6, 1, 5};
    sort(v.begin(), v.end());
    // cout<<"rahul";
    vector<vector<int>> fans = combinationSum(v, 8);
    for (int i = 0; i < fans.size(); i++)
    {
        for (int j = 0; j < fans[i].size(); j++)
            cout << fans[i][j] << " ";
        cout << endl;
    }
}
