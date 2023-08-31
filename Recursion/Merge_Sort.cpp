#include <bits/stdc++.h>
using namespace std;

void mergeS(vector<int> &arr, int low, int mid, int high) // merge()
{
    vector<int> temp;
    int i = low;
    int j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= high)
    {
        temp.push_back(arr[j]);
        j++;
    }

    cout<<"Temp:";
    for(auto item:temp){
        cout<<item<<" ";
    }
    cout<<endl;
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
        cout<<"Arr:";
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void divide(vector<int> &arr, int low, int high)  // mergeSort()
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    divide(arr, low, mid); // left
    divide(arr, mid + 1, high); // right
    mergeS(arr, low, mid, high); // merge in sorted manner
}

int main()
{
    vector<int> arr;
    int n;
    cin>>n;
    int val;
    for(int i=0;i<n;i++){
        cin>>val;
        arr.push_back(val);
    }
    cout<<"Before Merge Sort:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    divide(arr, 0, n-1);

    cout<<"After Merge Sort:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}