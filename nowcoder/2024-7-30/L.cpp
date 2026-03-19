#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
void solve(){
    ll n;
    cin >> n;
    vector<ll>a(n);
    vector<ll>b(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    for (int t=0;t<n*2;t++){
        for (int i=1;i<n;i++){
            if (a[i] > a[i-1]){
                ll n1,n2;
                n1 = (a[i]+a[i-1]) / 2 + (a[i]+a[i-1]) % 2;
                n2 = (a[i]+a[i-1]) / 2;
                a[i] = n2;
                a[i-1] = n1;
            }
        }
    }
    ll ans = 1;
    for (int i=0;i<n;i++){
        (ans *= a[i]) %= mod;
    }
    cout << ans%mod << '\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll T;
    cin >> T;
    while (T--){
        solve();
    }
}

/*
7
1 2 5 4 3 6 4
6912

3
1 1 100
39304
*/