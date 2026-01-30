

#include <bits/stdc++.h>
#define dbl double
#define ll long long
#define ln "\n"
#define all(a)  a.begin(),a.end()
// #define MOD 998244353
// #define mod 998244353
#define INF 1000000
using namespace std;
const int MAXN = 1000000;

ll fact[MAXN+1], invfact[MAXN+1];

ll binexp(ll base , ll pow,ll m){
    if(pow==0) return 1;
    ll ans=1;

    while(pow){
        if(pow%2==0) {
           base*=base;
           base%=m;
           pow/=2;
        }
        else {
            pow-=1;
            ans=(ans*base)%m;
        }
    }
    return ans;
}


ll modpow(ll a, ll b, ll m) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

void precompute(ll MOD) {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) fact[i] = (fact[i-1] * i) % MOD;
    invfact[MAXN] = modpow(fact[MAXN], MOD-2, MOD); // Fermat’s little theorem
    for (int i = MAXN-1; i >= 0; i--) invfact[i] = (invfact[i+1] * (i+1)) % MOD;
}

ll nCr(int n, int r,ll MOD) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n-r] % MOD;
}

bool isprime(ll n){
   if(n==2) true;
   for(ll i=2;i*i<=n;i++){
    if(n%i==0) return false;
   }
   return true;
}
ll gcd(ll a,ll b){
    while(b){
        ll temp=a%b;
        a=b; b=temp;
    }return a;
}
ll lcm(ll a,ll b){
    return (a*b)/gcd(a,b);
}
// extended euclid
ll solve(ll a,ll b,ll &x, ll &y){
    if(a==0){
        x=0; y=1; return b;
    }
    ll x1,y1;
    ll g=solve(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return g;
}
void helper(){
    ll a,b;
    cin>>a>>b;
    ll x,y;
    solve(a,b,x,y);
    cout<<x<<" "<<y<<ln;
}

// Linear Diophantine equation
// ax+by=c 
// c%gcd(a,b)==0   infinite solution
// if not zero solution

// bin exponentiation 


// modular arithmatic

void modarth(ll mod){
    ll a; cin>>a;
    ll inverse=binexp(a,mod-2,mod);
    cout<<inverse<<ln;
}
 
// sieve of erastotenes

 const int N=1e6;
 int sieve[N+1];
 
 void sieve_comp(){
   for(int i=2;i<=N;i++){
    sieve[i]=1;
   }
   for(int i=1;i*i<=N;i++){ 
    if(sieve[i]==0) continue;
    for(int j=i*i;j<=N;j+=i){
      sieve[j]=0;
    }
   }
   int l,r;
   cin>>l>>r;
   int cnt=0;
   for(int i=l;i<=r;i++){
   cnt+=sieve[i];
   } 
   cout<<cnt<<ln;
 }
int spf[N+1];
void pfac(){ 
    for(int i=1;i<=N;i++){
        spf[i]=i;
    }
    for(int i=2;i*i<=N;i++){
        if(spf[i]!=i) continue;
        for(int j=i;j<=N;j+=i){
           if(spf[j]==j) spf[j]=i;
        }
    }
    int q; cin>>q;
    while(q--){
        int n; cin>>n;
        while(n!=1){ 
           cout<<spf[n]<<" ";
           n/=spf[n];
        }
    }
    cout<<ln;
}

void f(){
    int primecnt[N+1];

     for(int i=1;i<=N;i++){
        primecnt[i]=0;
        spf[i]=i;
        
     }

     for(int i=2;i*i<=N;i++){
        if(spf[i]!=i) continue;
        for(int j=i;j<=N;j+=i){
            if(spf[j]==j) {
            spf[j]=i;
            primecnt[i]+=1;
            }
        }
     }


    int q; cin>>q;
    int n=1e6;
    while(q--){
        int x; cin>>x; 
       cout<<primecnt[x]<<ln;

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
   int t;
   cin>>t;
   while(t--){
    
    int n,k,l,r;
    cin>>n>>k>>l>>r;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
   
    


   }



    return 0;
}
