#include <bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()
#define ln "\n" 
using namespace std;

// any linear ordering of vertices such that if there is an edge between
// u and v ,u appers before v in that ordering

void dfs(int node,vector<set<int>>&edges,vector<bool>&vis,stack<int>&st){
      vis[node]=true;
      for(auto child:edges[node]){
        if(vis[child]==true){
          continue;
        }
        dfs(child,edges,vis,st);
      }
      st.push(node);
}
void bfs(){
    vector<vector<int>>edges;
    int n=edges.size();
    vector<int>indeg(n+1,0);
    for(int i=0;i<n;i++){
        for(auto ele:edges[i]){
            indeg[ele]++;
        }
    }
    queue<int>q;
    for(int i=0;i<indeg.size();i++){
        if(indeg[i]==0) q.push(i);
    }
    vector<int>res;
    while(!q.empty()){
        int node=q.front();
        res.push_back(node);
        for(auto child:edges[node]){
            indeg[child]--;
            if(indeg[child]==0) q.push(child);
        }
    }



}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);



    return 0;
}