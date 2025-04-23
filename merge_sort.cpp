#include <bits/stdc++.h>
using namespace std;
void mergesort(vector<int>&arr,int low,int high,int mid)
{
    int left=low;
    int right=mid+1;
    vector<int>temp;
    while(left<=mid && right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high)
    {
        temp.push_back(arr[right]);
            right++;
    }
    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i-low];
    }
}
void merge(vector<int>&arr,int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        merge(arr,low,mid);
        merge(arr,mid+1,high);
        mergesort(arr,low,high,mid);
    }
}
int main()
{
    vector<int>arr={5,4,3,2,1};
    int n=arr.size();
    merge(arr,0,n-1);
    for(int num:arr)
    {
        cout<<num;
    }
    return 0;
}