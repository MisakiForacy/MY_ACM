#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        ll a,b,k;
        cin >> a >> b >> k;
        ll x = a/k + (a%k?1:0);
        ll y = b/k + (b%k?1:0);
        ll ans;
        if (y<x) ans = x*2 - (b-x*k>0?0:1);
        else ans = 2 * y;
        cout << ans << '\n';
    }
}