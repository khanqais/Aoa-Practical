#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>ans;
vector<int>arr={1,2,3,4,5,6};
int m=5,n=6;
void sum_of_subset(int rsum,int count,vector<int>&sets)
{
    if(rsum==m) {
        ans.push_back(sets);
        return;
    }
    if(rsum>m || count>=n)
    return;
    sets.push_back(arr[count]);
    sum_of_subset(rsum+arr[count],count+1,sets);
    sets.pop_back();
    sum_of_subset(rsum,count+1,sets);

}
int main()
{
    

    
    int x=accumulate(arr.begin(),arr.end(),0);
    vector<int>sets;
    sum_of_subset(0,0,sets);
    return 0;

}