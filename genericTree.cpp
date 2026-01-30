#include <bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()
#define ln "\n" 
using namespace std;

vector<ll>p;
vector<ll>childh;
vector<ll>ctzn;
vector<ll>h;
vector<ll>unhappy;


void dfs(int node,vector<int>adj[],int par,vector<int>&level,int l=0){
    // we are entering the node
    // cout<<node<<" ";
    level[node]=l;
    p[node]+=ctzn[node];
    for(auto child:adj[node]){
        if(child==par) continue;
        dfs(child,adj,node,level,l+1);
        childh[node]+=h[child];
        p[node]+=p[child];
    }
     
    // we are leaving the node
}
void bfs(int node,vector<int>adj[],int par,vector<int>&level,int l=0){
    queue<pair<int,int>>q;
    q.push({node,par});

    while(!q.empty()){
        int k=q.size();
        for(int i=0;i<k;i++){
            int curnode=q.front().first;
            int curpar=q.front().second;
           p[curnode]=curpar;
            level[curnode]=l;
            cout<<curnode<<" ";
        for(auto child:adj[curnode]){
           if(child==curpar)continue;
           q.push({child,curnode});
        }
        q.pop();
        } l++;
    }
    cout<<ln;
}

// int lca(int node1,int node2,vector<int>adj[],vector<int>level){
//      int level1=level[node1];
//      int level2=level[node2];
//      int dif=abs(level1-level2);
//      if(level1>level2){
//         swap(node1,node2);
//      }
//      int cnt=0;
//      while(dif){
//         if(dif&1){
//             node2=p[node2][cnt];
//         }
//         cnt++; dif=dif>>1;
//      }
//     for(int i=19;i>=0;i--){
//         if(p[node1][i]!=p[node2][i]){
//             node1=p[node1][i];
//             node2=p[node2][i];
//         }
//     }
//     return p[node1][0];

// }



void solve(){
    ll n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    ctzn.assign(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>ctzn[i];
    }
    h.assign(n+1,0);
    for(int i=1;i<=n;i++) cin>>h[i];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    p.assign(n+1,0);
    childh.assign(n+1,0);
    vector<int>level(n+1,-1);
    dfs(1,adj,0,level);
 

   
 
   
}




int main(){
  ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
    solve();
}
    return 0;
}