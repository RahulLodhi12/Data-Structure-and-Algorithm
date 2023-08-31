#include <bits/stdc++.h>
using namespace std;

bool printSubsequences(int i, int arr[], vector<int> &vec, int n, int sum, int k)
{
    if (i >= n)
    {
        //condn satisfied
        if (sum == k)
        {
            for (auto item : vec)
                cout << item << " ";
            cout << endl;
            return true;
        }
        //condn not satisfied
        else 
            return false;
    }
    vec.push_back(arr[i]);
    sum += arr[i];
    if(printSubsequences(i + 1, arr, vec, n, sum, k)==true) return true; // Take

    vec.pop_back();
    sum -= arr[i];
    if(printSubsequences(i + 1, arr, vec, n, sum, k)==true) return true; // Not Take

    return false;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cout << "k : ";
    cin >> k;
    vector<int> vec;
    printSubsequences(0, arr, vec, n, 0, k);
}