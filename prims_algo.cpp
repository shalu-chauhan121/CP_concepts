#include <bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()
#define ln "\n" 
#define ss second
#define ff first
#define mod 998244353
#define dummy (1LL<<30)-1
using namespace std;

class Solution {
  public:
    int spanningTree(int n, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>graph(n);
        int sz=edges.size();
        for(int i=0;i<sz;i++){
            int from=edges[i][0]; int to=edges[i][1]; int wt=edges[i][2];
            graph[from].push_back({to,wt});
            graph[to].push_back({from,wt});
        }
        vector<int>vis(n,0);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
       // wt,node,par
        pq.push({0,{0,-1}});
        int sum=0;
        while(!pq.empty()){
            auto ele=pq.top(); pq.pop();
            int node=ele.second.first; int par=ele.second.second;
            if(vis[node]==1) continue;
            sum+=ele.first;
            vis[node]=1;
            for(auto child:graph[node]){
                if(vis[child.first]==1 || child.first==par) continue;
                pq.push({child.second,{child.first,node}});
            }
        }
        return sum;
    }
};