#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
#define ll long long
#define mod 1000000007

struct FenwickTree{
    int n;
    vector<int>bit;

    FenwickTree(vector<int>&a){
        n=a.size();
        bit.assign(n+1,0);
        for(int i=0;i<n;i++) upd(i,a[i]);
    }
    void upd(int i,int x){
        for(i++;i<=n;i+=i&-i) bit[i]+=x;
    }
    int sum(int i){
        int s=0;
        for(i++;i>0;i-=i&-i) s+=bit[i];
        return s;
    }
    int query(int l,int r){
        return sum(r)-sum(l-1);
    }
};
struct FenwickTree2D {
      int n,m;
      vector<vector<int>>bit;
      FenwickTree2D(vector<vector<int>>&a){
        n=a.size();
        m=a[0].size();
        bit.assign(n+1,vector<int>(m+1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                upd(i,j,a[i][j]);
            }
        }
      }
      void upd(int r,int c,int x){
         for(int i=r+1;i<=n;i+=i&-i){
            for(int j=c+1;j<=m;j+=j&-j){
                bit[i][j]+=x;
            }
         }
      }
      int sum(int r,int c){
        int s=0;
        for(int i=r+1;i<=n;i-=i&-i){
            for(int j=c+1;j<=m;j-=j&-j){
                s+=bit[i][j];
            }
        }
        return s;
      }
      int query(int r1,int c1,int r2,int c2){
      return sum(r2,c2)-sum(r1-1,c2)-sum(r2,c1-1)+sum(r1-1,c1-1);
      }

};

struct SparseTable {
    int n, LOG;
    vector<vector<int>> st;
    vector<int> log2val;

    // CHANGE THIS MERGE FUNCTION
    int merge(int a, int b) {
        return min(a, b);   // for RMQ
        // return max(a, b);
        // return __gcd(a, b);
        // return (a | b);
        // return (a & b);
    }

    SparseTable(vector<int>& a) {
        n = a.size();
        LOG = log2(n) + 1;

        st.assign(n, vector<int>(LOG));
        log2val.assign(n + 1, 0);

        // Precompute logs
        for (int i = 2; i <= n; i++)
            log2val[i] = log2val[i/2] + 1;

        // Base case (interval length = 1)
        for (int i = 0; i < n; i++)
            st[i][0] = a[i];

        // Build table
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = merge(st[i][j-1],
                                 st[i + (1 << (j-1))][j-1]);
            }
        }
    }

    // Query on [L, R]
    int query(int L, int R) {
        int len = R - L + 1;
        int k = log2val[len];
        return merge(st[L][k],
                     st[R - (1 << k) + 1][k]);
    }
};

int main(){
    vector<int>a={1,2,3,4,5,6};
    FenwickTree bit(a);

}