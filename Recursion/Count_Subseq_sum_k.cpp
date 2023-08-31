#include <bits/stdc++.h>
using namespace std;

// int cnt = 0; // global variable is not allowed
int printSubsequences(int i, int arr[], int n, int sum, int k)
{
    // condn not satisfied
    if (sum > k)
        return 0; // strictly done if array contains positives only.

    if (i >= n)
    {
        // condn satisfied
        if (sum == k)
            return 1;

        // condn not satisfied
        else
            return 0;
    }
    sum += arr[i];
    int l = printSubsequences(i + 1, arr, n, sum, k); // Take

    sum -= arr[i];
    int r = printSubsequences(i + 1, arr, n, sum, k); // Not Take

    return l + r;
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

    cout << printSubsequences(0, arr, n, 0, k);
}