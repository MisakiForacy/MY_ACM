#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
const int MAXN = 1000005; // 1e6 + 5
static ll fac[MAXN], ifac[MAXN];

ll modpow(ll a, ll e){ ll r=1; while(e){ if(e&1) r=r*a%MOD; a=a*a%MOD; e>>=1;} return r; }

void init_fac(){ fac[0]=1; for(int i=1;i<MAXN;i++) fac[i]=fac[i-1]*i%MOD; ifac[MAXN-1]=modpow(fac[MAXN-1], MOD-2); for(int i=MAXN-2;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%MOD; }

ll comb(int n,int k){ if(k<0||k>n) return 0; return fac[n]*ifac[k]%MOD*ifac[n-k]%MOD; }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init_fac();
    int T; if(!(cin>>T)) return 0;
    while(T--){
        int n,x,t; cin>>n>>x>>t;
        int r = t+1;
        if(r>n){ cout<<0<<"\n"; continue; }
        ll ans=0;
        // start with 1
        {
            int k1 = (r+1)/2;
            int k0 = r - k1;
            bool ok = true;
            if(k1<1) ok = (x==0);
            if(k1> x) ok = false;
            if(k0==0){ if(n-x!=0) ok = false; }
            else if(n-x < k0) ok = false;
            if(ok){
                ll a = (k1==0? (x==0?1:0) : comb(x-1, k1-1));
                ll b = (k0==0? (n-x==0?1:0) : comb(n-x-1, k0-1));
                ans = (ans + a*b) % MOD;
            }
        }
        // start with 0
        {
            int k1 = r/2;
            int k0 = r - k1;
            bool ok = true;
            if(k1==0){ if(x!=0) ok = false; }
            else if(k1> x) ok = false;
            if(k0<1) ok = (n-x==0);
            if(k0> n-x) ok = false;
            if(ok){
                ll a = (k1==0? (x==0?1:0) : comb(x-1, k1-1));
                ll b = (k0==0? (n-x==0?1:0) : comb(n-x-1, k0-1));
                ans = (ans + a*b) % MOD;
            }
        }
        cout<<ans%MOD<<"\n";
    }
    return 0;
}
