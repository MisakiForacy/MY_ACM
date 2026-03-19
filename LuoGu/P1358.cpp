#include <bits/stdc++.h>
#define debug(x) cerr << #x << " : " << x << '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod = 10007;
ull fac[10005],inv[10005];
ll qpower(ll a,ll k,ll p){
    ll res = 1;
    while (k){
        if (k&1) res = res * a % p;
        a = a * a % p;
        k >>= 1;
    }
    return res;
}
void f(){
    fac[0] = fac[1] = 1;
    inv[0] = qpower(fac[0],mod-2,mod);
    for (int i=1;i<=10000;i++){
        fac[i] = fac[i-1] * i % mod;
        inv[i] = qpower(fac[i],mod-2,mod);
    }
}
ll cal(ll n,ll m){
    // debug(fac[m]), debug(inv[n]);
    return (fac[m]*inv[n]%mod*inv[m-n]%mod);
}
int main(){
    f();
    int n,m;
    cin >> n >> m;
    vector<int> a(m);
    ll res = n;
    ll ans = 1;
    for (int i=0;i<m;i++){
        cin >> a[i];
        ans *= cal(a[i],res);
        // debug(a[i]);
        // debug(res);
        // debug(cal(a[i],res));
        ans %= mod;
        res -= a[i];
    }
    cout << ans << '\n';
}