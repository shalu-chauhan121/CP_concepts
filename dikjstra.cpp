#include <bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()
#define ln "\n" 
using namespace std;


void dikjstra(int node,int n,vector<vector<pair<int,int>>>&adj,vector<int>&dist){
    fill(all(dist),INFINITY);
    dist[node]=0LL;
    vector<bool>vis(n,false);
    set<pair<int,int>>to_explore;
    to_explore.insert({dist[node],node});
    while(sizeof(to_explore)>0){
        auto top=*to_explore.begin();
        to_explore.erase(top);
        int poppedNode=top.second;
        int d=top.first;
        vis[poppedNode]=true;
        for(auto child:adj[poppedNode]){
            int child_node=child.first;
            int added_dist=child.second;
            if(vis[child_node]) continue;
            if(dist[child_node]>d+added_dist){
                to_explore.erase({dist[child_node],child_node});
                dist[child_node]=d+added_dist;
                to_explore.insert({dist[child_node],node});
            }
        }

    }
}
void helper(int node,int n,vector<int>&parent,vector<ll>&dist,vector<vector<pair<ll,ll>>>&adj)
{
    fill(all(dist),INFINITY);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
    dist[node]=0;
    q.push({dist[node],node});
    while(!q.empty()){  // how many time will this run O(n)
        pair<ll,ll> top=q.top();
        q.pop();          //O(logn)
        int popped_node=top.second;
        int d=top.first;
        if(d!=dist[popped_node]){
            continue;
        }
        for(auto child:adj[popped_node]){  // O(m) in total for all the steps
            if(dist[child.first]>d+child.second){
                dist[child.first]=d+child.second;
                q.push({dist[child.first],child.first});   // O(logn)
                parent[child.first]=popped_node;
            }
        }
        //O(nlogn +mlogn)=O((n+m)logn) 
    }
}
void getpath(int node,vector<int>&parent){
    while(node!=-1){
        cout<<node<<" ";
        node=parent[node];
    }
}
int main(){

      

    return 0;
}