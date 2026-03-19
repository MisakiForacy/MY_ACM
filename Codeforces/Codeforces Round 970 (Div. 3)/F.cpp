#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p = 1e9+7;
ll qpower(ll a,ll k,ll mod){
    ll res = 1;
    while (k){
        if (k&1) res = res * a % mod;
        a = a * a % mod;
        k >>= 1;
    }
    return res;
}
ll divi(ll a,ll b){
    return a * (qpower(b,p-2,p) % p) % p;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n; cin >> n;
        vector<ll> a(n+1), pre(n+1,0);
        for (int i=1;i<=n;i++){
            cin >> a[i];
            pre[i] = pre[i-1] + a[i];
        }
        ll P,Q;
        P = 0, Q = n * (n-1) / 2 % p;
        for (int i=1;i<=n;i++){
            P = P + a[i] * ((pre[n]-pre[i]) % p) % p;
            P %= p;
        }
        cout << divi(P,Q) << '\n';
    }
}