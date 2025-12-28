#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
#define ll long long
#define all(a) a.begin(),a.end()
#define mod 1000000007

vector<vector<int>> segTree, lazy;

vector<int> merge(vector<int> a,vector<int> b){
      vector<int>res(25,0);
      for(int i=0;i<25;i++) 

      {
        res[i]+=a[i];
        res[i]+=b[i];
      }

    return res;
}

void build(vector<int>&a,int start,int end,int index){
    if(start==end){
        int val=a[start];
        for(int i=0;i<25;i++){
            if((1<<i)&val){
                segTree[index][i]=1;
            }
        }
        return;
    }
    int mid=(start+end)/2;
    build(a,start,mid,2*index);
    build(a,mid+1,end,2*index+1);
    segTree[index]=merge(segTree[2*index],segTree[2*index+1]);
}
bool hasLazy(int idx){
    for(int i=0;i<25;i++){
        if(lazy[idx][i]) return true;
    }
    return false;
}

void push(int index,int start,int end){
    if(hasLazy(index)){
        vector<int> v=lazy[index];
        int cnt=end-start+1;
        int cnt1=(end-start)/2+1;
        int cnt2=cnt-cnt1;
        for(int i=0;i<25;i++){
            if(v[i]==1){
                if(segTree[2*index][i]==0)
            segTree[2*index][i]=cnt1;
            else segTree[2*index][i]=cnt1-segTree[2*index][i];
             if(segTree[2*index+1][i]==0)
            segTree[2*index+1][i]=cnt2;
            else segTree[2*index+1][i]=cnt2-segTree[2*index+1][i];
             if(lazy[2*index][i]) lazy[2*index][i]=0;
                else lazy[2*index][i]=1;
            if(lazy[2*index+1][i]) lazy[2*index+1][i]=0;
                else lazy[2*index+1][i]=1;
            }
           
        }
        for(int i=0;i<25;i++) lazy[index][i]=0;

    }
}

void update(int start,int end,int index,int l,int r,ll val){
    if(start>r || end<l) return;
     
    if(start>=l && end<=r){
        for(int i=0;i<25;i++){
            if((1<<i)&val){
                int cnt=end-start+1;
                if(segTree[index][i]) segTree[index][i]=cnt-segTree[index][i];
                else segTree[index][i]=cnt;
                if(lazy[index][i]) lazy[index][i]=0;
                else lazy[index][i]=1;
            }
        }
        return;
    }
    push(index,start,end);


    int mid=(start+end)/2;
    update(start,mid,2*index,l,r,val);
    update(mid+1,end,2*index+1,l,r,val);

    segTree[index]=merge(segTree[2*index],segTree[2*index+1]);
}

ll query(int start,int end,int index,int l,int r){
    if(start>r || end<l) return 0;

    if(start>=l && end<=r){
        ll res=0;
        for(int i=0;i<25;i++){
            res+=(segTree[index][i]*(1LL<<i));
        }
     return res;                                                    
     }
    push(index,start,end);      


    int mid=(start+end)/2;
    ll leftans=query(start,mid,2*index,l,r);
    ll rightans=query(mid+1,end,2*index+1,l,r);
    return leftans+rightans;
}

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    segTree.assign(4*n,vector<int>(25,0));
    lazy.assign(4*n,vector<int>(25,0));
    build(a,0,n-1,1);
    int m;
    cin>>m;
    while(m--){
        int t;
        cin>>t;
        if(t==1){
          int l,r;
          cin>>l>>r; l--; r--;
         ll res=query(0,n-1,1,l,r);
          cout<<res<<ln;
        }
        else{

            int l,r,val;
            cin>>l>>r>>val;
            l--;r--;
            update(0,n-1,1,l,r,val);

        }

    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin>>n;
    ll cnt=n;
    vector<ll>a; ll temp=1;
    for(ll i=1;i<=n;i++){
        a.push_back(cnt*temp); cnt--; temp++;

    }
    sort(all(a));
    // for(int i=0;i<a.size();i++) cout<<a[i]<<" "; cout<<ln;
    ll res=a[n/2];
    cout<<res<<ln;


}
