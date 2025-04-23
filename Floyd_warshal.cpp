#include <iostream>
#include <vector>
#include <climits>
using namespace std;
void floyed(vector<vector<int>>&dist,vector<vector<int>>&pi,int V)
{
       for(int k=0;k<V;k++)
       {
           for(int i=0;i<V;i++)
           {
              for(int j=0;j<V;j++)
              {
                  if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX && dist[i][j]>dist[i][k]+dist[k][j])
                  {
                    dist[i][j]=dist[i][k]+dist[k][j];
                    pi[i][j]=pi[i][k];
                  }
              }
           }
       }
}
int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout<<"Enter the matrix, -1 for not ,0 for self loop";
    vector<vector<int>>dist(V,vector<int>(V));
    vector<vector<int>>pi(V,vector<int>(V,-1));
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cin>>dist[i][j];
            if(dist[i][j]==-1 && i!=j)
            {
                dist[i][j]=INT_MAX;
            }
            if(dist[i][j]!=INT_MAX && i!=j)
            pi[i][j]=i;

        }

    }
    floyed(dist,pi,V);
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cout<<dist[i][j];
        }
        cout<<endl;
    }
    
}