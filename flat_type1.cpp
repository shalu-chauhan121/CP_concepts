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

vector<int>flat,level;
map<int,int>mp;
int idx=0;

void dfs(int node, int par, vector<int>adj[],int l=1){
    flat.push_back(node);
    level[node]=l;
    if(mp.find(node)==mp.end()){
        mp[node]=idx;
    } 
    idx++;
    for(auto child:adj[node]){
        if(child==par)  continue;
        dfs(child,node,adj,l+1);
        flat.push_back(node); idx++;
    }
  
}

vector<int>segTree;
int merge(int a,int b){
    return min(a,b);
}
void build(vector<int>&a,int start,int end,int index){
    if(start==end){
      segTree[index]=a[start];
      return;
    }
    int left=2*index;
    int right=2*index+1;
    int mid=(start+end)/2;
    build(a,start,mid,left);
    build(a,mid+1,end,right);
    segTree[index]=merge(segTree[left],segTree[right]);

}

int query(vector<int>&a,int start,int end,int l,int r,int index){
    if(start>=l && end<=r){
        return segTree[index];
    }
    if(start>r || end<l){
        return INT_MAX;
    }
    int mid=(start+end)/2;
    return merge(query(a,start,mid,l,r,2*index),query(a,mid+1,end,l,r,2*index+1));
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
    flat.clear();
    level.assign(n+1,0);
    dfs(1,0,adj);
    for(int i=0;i<flat.size();i++) cout<<flat[i]<<" "; cout<<ln;
    for(int i=1;i<=n;i++) cout<<i<<" "<<mp[i]<<ln;

    vector<int>l;
    for(int i=0;i<flat.size();i++){
        l.push_back(level[flat[i]]);
    }
    int sz=flat.size();
    segTree.assign(4*sz,0);
    build(l,0,sz-1,1);

    int u,v;
    cin>>u>>v;
    int l=mp[u]; int r=mp[v];
    int mn=query(l,0,sz-1,l,r,1);
    





    

    return 0;
}    
