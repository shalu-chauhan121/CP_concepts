#include <bits/stdc++.h>
#define dbl double
#define ll long long
#define ln "\n"
#define all(a) a.begin(), a.end()
#define MOD 998244353
#define mod 998244353
#define INF 1000000
using namespace std;
const int MAXN = 1000005;


// euler tour
// lca by calculating the element at the lower level between the first index of the given elements


void indfs(int node,int par,vector<int>adj[],vector<int>&indp){
    for(auto child:adj[node]){
        if(child==par) continue;
        indfs(child,node,adj,indp);
        indp[node]=max(indp[node],1+indp[child]);
    }
}

void outdfs(int node,int par,vector<int>adj[],vector<int>&outdp,vector<int>&indp){
    int mx1=-1; int mx2=-1;
    for(auto child:adj[node]){
        if(child==par) continue;
        if(indp[child]>mx1){
            mx2=mx1; mx1=indp[child];
        }
        else if(indp[child]>mx2){
            mx2=indp[child];
        }
    }
    for(auto child:adj[node]){
        int longest=mx1;
        if(child==par) continue;
        if(mx1==indp[child]){
           longest=mx2;
        }
        outdp[child]=1+max(outdp[node],longest+1);
        outdfs(child,node,adj,outdp,indp);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<int>adj[n+1];
    for(int i=0;i<n-1;i++){
        int u,v;
         cin>>u>>v;
         adj[u].push_back(v);
         adj[v].push_back(u);
    }
    vector<int>indp(n+1,0),outdp(n+1,0);
    indfs(1,0,adj,indp);
    outdfs(1,0,adj,outdp,indp);
    // for(int i=1;i<=n;i++) cout<<indp[i]<<" "; cout<<ln;
    for(int i=1;i<=n;i++){
        cout<<max(outdp[i],indp[i])<<" ";
    }
    cout<<ln;
    

    return 0;
}    
