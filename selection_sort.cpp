#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>arr={5,4,3,2,1};
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        int mini=INT_MAX;
        int index=i;
        for(int j=i;j<n;j++)
        {
            if(arr[j]<mini) {
                mini=arr[j];
                index=j;
            }
        }
        swap(arr[i],arr[index]);
        
    }
    for(int num:arr)
    cout<<num;
    return 0;
}