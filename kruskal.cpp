#include <bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()
#define ln "\n" 
#define ss second
#define ff first
#define mod 998244353
#define dummy (1LL<<30)-1
using namespace std;


// to calculate the minimum spanning tree and minimum spanning tree sum

class disjointSet{
    vector<int>rank,parent,size;
    public:
    disjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
        parent[i]=i;
        }
    }
   int findUpar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUpar(parent[node]);
    }
    void unionByrank(int u,int v){
       int up_u=findUpar(u);
       int up_v=findUpar(v);
       if(up_v==up_u) return;
       if(rank[up_v]>rank[up_u]){
        parent[up_u]=up_v;
       }
       else if(rank[up_u]>rank[up_v]) {
        parent[up_v]=up_u;
       }else {
        parent[up_v]=up_u;
        rank[up_u]++;
       }
    }
    void unionBysize(int u,int v){
        int up_u=findUpar(u);
        int up_v=findUpar(v);
        if(up_v==up_u) return;
        if(size[up_u]>size[up_v]){
            parent[up_v]=up_u;
            size[up_u]+=size[up_v];
        }else{
            parent[up_u]=up_v;
            size[up_v]+=size[up_u];
        }
    }
};


class Solution {
  public:
    int spanningTree(int n, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,pair<int,int>>>graph;
        int sz=edges.size();
        for(int i=0;i<sz;i++){
            int from=edges[i][0]; int to=edges[i][1]; int wt=edges[i][2];
            graph.push_back({wt,{from,to}});
        }
        int sum=0;
        disjointSet ds(n);
        sort(graph.begin(),graph.end());
        for(int i=0;i<sz;i++){
            if(ds.findUpar(graph[i].second.first)!=ds.findUpar(graph[i].second.second)){
                sum+=graph[i].first;
                ds.unionBysize(graph[i].second.first,graph[i].second.second);
            }
        }
        return sum;
    }
};