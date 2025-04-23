
#include <bits/stdc++.h>
using namespace std;
int partition(vector<int>& arr, int low, int high) {
    int pivotValue = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && arr[i] <= pivotValue) i++;
        while (j >= low && arr[j] > pivotValue) j--;
        if (i < j) swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]); 
    return j; 
}

void QuickSort(vector<int>&arr,int low,int high)
{
    if(low<high)
    {
        int p=partition(arr,low,high);
        QuickSort(arr,low,p-1);
        QuickSort(arr,p+1,high);
    }
}
int main()
{
    vector<int>arr={5,4,3,2,1};
    int n=arr.size();
    QuickSort(arr,0,n-1);
    for(int num:arr)
    {
        cout<<num;
    }
    return 0;
}