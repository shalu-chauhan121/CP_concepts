#include <bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()
#define ln "\n" 
#define ss second
#define ff first
#define mod 1000000007
#define dummy (1LL<<30)-1
using namespace std;

map<int,int>mp;
vector<int>flat,level;
int idx;
void dfs(vector<int>adj[],int node,int par,int l=1){
    level[node]=l;
    flat.push_back(node); idx++;
    if(mp.find(node)==mp.end()) mp[node]=idx;
    for(auto child:adj[node]){
        if(child==par) continue;
        dfs(adj,child,node,l+1);
        flat.push_back(node); idx++;
    }
}
int merge(int a, int b){
    return min(a,b);
}
vector<int>segTree;
void build(vector<int>&a,int start,int end,int index){
    if(start==end){
        segTree[index]=a[start];
        return;
    }
    int mid=(start+end)/2;
    build(a,start,mid,2*index);
    build(a,mid+1,end,2*index+1);
    segTree[index]=merge(segTree[2*index],segTree[2*index+1]);
}
int query(int start,int end,int index,int l, int r){
    if(start>=l && end<=r) return segTree[index];
    if(start>r || end<l) return INT_MAX; 
    int mid=(start+end)/2;
    int left=query(start,mid,2*index,l,r);
    int right=query(mid+1,end,2*index+1,l,r);
    return merge(left,right);
}
void lca(){
        int n;
        cin>>n;
        vector<int>adj[n+1];
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int a,b;
        cin>>a>>b;
        level.assign(n+1,0);
        flat.clear();
        dfs(adj,1,0);
        int sz=flat.size();
        segTree.assign(4*sz,0);
        build(flat,0,sz-1,1);
        int l=mp[a];int r=mp[b];
        int mnlevel=query(0,sz-1,1,l,r);
        int ele=-1;
        for(int i=l;i<=r;i++){
            if(level[flat[i]]==mnlevel){
                ele=flat[i];
            }
        }
        cout<<ele<<ln;
}
vector<int>flat2;
void dfs2(vector<int>adj[],int node,int par){
    flat2.push_back(node);
    for(auto child:adj[node]){
        if(child==par) continue;
        dfs2(adj,child,node);
    }
    flat2.push_back(node);
}
void print_flat2(){
    int n;
    cin>>n;
    vector<int>adj[n+1];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    flat2.clear();
    dfs2(adj,1,0);
    for(int i=0;i<flat2.size();i++) cout<<flat2[i]<<" ";
    cout<<ln;

}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    // int n;
    // cin>>n;
    // vector<int>adj[n+1];
    // for(int i=0;i<n-1;i++){
    //     int u,v;
    //     cin>>u>>v;
    //     adj[u].push_back(v);
    //     adj[v].push_back(u);
    // }

    print_flat2();

    




    return 0;
}