#include <bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()
#define ln "\n" 
using namespace std;

void dfs(int node,vector<vector<int>>&edges,vector<bool>&vis,int cnt,vector<int>comp){
      vis[node]=true;
      cout<<node<<" ";
      comp[node]=cnt;
      for(auto child:edges[node]){
        if(vis[child]==true) continue;
        dfs(child,edges,vis,cnt,comp);
      }
}

void bfs(int node,vector<vector<int>>&edges, vector<bool>&vis){
    queue<int>q;
    q.push(node);
    vis[node]=true;
    while(!q.empty()){
        int ele=q.front();
        cout<<ele<<" ";
        q.pop();
        for(auto child:edges[ele]){
            if(vis[child]!=true){
                vis[child]=true;
                q.push(child);
            }
        }

    }
    cout<<ln;
}
void cycledfs(int node,vector<vector<int>>edges,vector<bool>vis,int par){
    vis[node]=true;
    for(int child:edges[node]){
        if(child==par) continue;
        if(!vis[child]) {
            vis[child]=true;
        cycledfs(child,edges,vis,node);
        }
        else
         cout<<"Yes"<<ln;
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges(n+1,vector<int>());
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<bool>vis(n+1,false);
    int cnt=0; vector<int>comp(n+1);
    // for(int i=1;i<=n;i++){
    //     if(vis[i]!=true){
    //         cnt++;
    //         dfs(i,edges,vis,cnt,comp);
    //     }
    // }
    for(int i=1;i<=n;i++){
        if(vis[i]!=true){
            cycledfs(i,edges,vis,-1);
        }
    }
    cout<<ln;
    for(int i=0;i<=n;i++) vis[i]=false;
    bfs(1,edges,vis);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();



    return 0;
}