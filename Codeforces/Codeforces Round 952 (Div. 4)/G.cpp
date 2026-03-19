#include <bits/stdc++.h>
#define debug(x) cout << #x << ":" << x << '\n'
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll MOD(ll x){
    return (x%mod + mod) % mod;
}
ll qpow(ll a,ll x){
    ll res = 1;
    while (x){
        if (x&1) res = (res * a) % mod;
        a = (a*a)%mod;
        x >>= 1;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    ll l,r,k;
    cin >> T;
    while (T--){
        cin >> l >> r >> k;
        cout << MOD(qpow(9/k+1,r) - qpow(9/k+1,l)) << '\n';
    }
}