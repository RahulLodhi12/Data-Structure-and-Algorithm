#include <bits/stdc++.h>
using namespace std;

int placePivot(vector<int> &arr, int low, int high)// partition
//pick pivot and place it at correct position
{// by placing pivot at correct position, the smaller elements than pivot are 
// shifted to left side of pivot and larger element to the right side of pivot.
    int pivot = low;
    int p = low;
    int q = high;
    while (p < q)
    {
        while (arr[p] <= arr[pivot] && p <= high-1)
            p++;
        while (arr[q] > arr[pivot] && q >= low+1)
            q--;
        if (p < q)
            swap(arr[p], arr[q]);
    }
    swap(arr[pivot], arr[q]);
    return q;
}

void divide(vector<int> &arr, int low, int high)//call partition and divide array
{
    if (low >= high)
        return;
    int pIndex = placePivot(arr, low, high); // pick pivot and place it at correct position
    divide(arr, low, pIndex - 1); // left
    divide(arr, pIndex + 1, high); // right
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
    cout<<"Before Quick Sort:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    divide(arr, 0, n-1);
    cout <<"After Quick Sort:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}