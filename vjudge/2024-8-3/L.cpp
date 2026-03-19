#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
// typedef __int128_t ll;
const ll mod = 998244353;
int main(){
    ll n;
    ll ans = 0;
    cin >> n;
    vector<ll>a(n+1,0);
    vector<vector<ll>>pre(11,vector<ll>(n+1));
    for (ll i=1;i<=n;i++){
        cin >> a[i];
        (ans += a[i]%mod * (i-1))%mod;
        ll len = to_string(a[i]).length();
        pre[len][i] ++;
    }
    for (ll i=1;i<11;i++){
        for (ll j=1;j<=n;j++){
            pre[i][j] = pre[i][j] + pre[i][j-1];
        }
    }
    for (ll i=1;i<11;i++){
        for (ll j=1;j<=n;j++){
            (ans += ((a[j]*((pre[i][n]-pre[i][j])%mod))%mod*(ll(pow(10,i))%mod))%mod)%mod;
        }
    }
    cout << ans % mod << '\n';
}