
#include <bits/stdc++.h>
using namespace std;
class disjoint{
       vector<int>parent;
       vector<int>rank;
       public:
       disjoint(int n){
          rank.resize(n+1,0);
          parent.resize(n+1);
          for(int i=0;i<n;i++)
          {
            parent[i]=i;
          }
       }
       int findp(int node)
       {
           if(node==parent[node])
           return node;
           return parent[node]=findp(parent[node]);
       }
       void unionbyrank(int u,int v)
       {
           int ulp_u=findp(u);
           int ulp_v=findp(v);
           if(rank[ulp_u]<rank[ulp_v])
           {
              parent[ulp_u]=ulp_v;
           }
           else if(rank[ulp_u]>rank[ulp_v])
           {
             parent[ulp_v]=ulp_u;
           }
           else{
              rank[ulp_v]++;
              parent[ulp_u]=ulp_v;
           }
           
       }
};
class Solution{
    public:
    int spaning(vector<vector<int>>adj[],int V)
    {
        vector<pair<int,pair<int,int>>>edges;
        disjoint ds(V);
        for(int i=0;i<V;i++)
        {
             for(auto it:adj[i])
             {
                int adjnode=it[0];
                int w=it[1];
                int node=i;
                edges.push_back({w,{node,adjnode}});
             }
        }
        sort(edges.begin(),edges.end());
        int mstw=0;
        for(auto it:edges)
        {
           int w=it.first;
           int u=it.second.first;
           int v=it.second.second;
           if(ds.findp(u)!=ds.findp(v))
           {
               mstw+=w;
               ds.unionbyrank(u,v);
           }
        }
        return mstw;
    }

};
int main()
{
    int n;
    cout<<"Enter the number of vertices";
    cin>>n;
    int E;
    cout<<"Enter the number of Edges";
    cin>>E;
    vector<vector<int>>adj[n+1];
    cout<<"Enter the edj and weight (u v w)";
    for(int i=0;i<E;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        vector<int>t1,t2;
        t1.push_back(v);
        t1.push_back(w);
        adj[u].push_back(t1);

        t2.push_back(u);
        t2.push_back(w);
        adj[v].push_back(t2);
    }
    Solution obj;
    cout<<obj.spaning(adj,n);

    return 0;
}