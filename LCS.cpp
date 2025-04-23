#include <bits/stdc++.h>
using namespace std;



void longestCommonSubsequence(string X, string Y) {
   int m=X.length(),n=Y.length();
   vector<vector<int>>LCS(m+1,vector<int>(n+1,0));
   vector<vector<char>> dir(m+1,vector<char>(n+1,' '));

   for(int i=1;i<=m;i++)
   {
       for(int j=1;j<=n;j++)
       {
          if(X[i-1]==Y[j-1])
          {
            LCS[i][j]=LCS[i-1][j-1]+1;
            dir[i][j]='S';
          }
          else if(LCS[i-1][j]>=LCS[i][j-1])
          {
             //uper
          }
          else {
              //left
          }
       }
   }
   int index=LCS[m][n];
   string l(index,'\0');
   int i=m,j=n;
   while(i>0 && j>0)
   {
       if(X[i-1]==Y[j-1])
       {
           l[index-1]=X[i-1];
           i--;
           j--;
           index--;
       }
       else if(LCS[i-1][j]>LCS[i][j-1]){
            i--;
       }
       else{
           j--;
       }
   }

}

int main() {
    string X, Y;
    cout << "Enter string X: ";
    cin >> X;
    cout << "Enter string Y: ";
    cin >> Y;
    longestCommonSubsequence(X, Y);
    return 0;
}
