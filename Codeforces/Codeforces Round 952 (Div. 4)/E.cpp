#include <bits/stdc++.h>
#define debug(x) cerr << #x << ":" << x << '\n'
using namespace std;
typedef unsigned long long ll;
void solve(){
    ll x,y,z,k,ans;
    cin >> x >> y >> z >> k;
    ans = 0;
    for (ll i=1;i<=x;i++){
        for (ll j=1;j<=y;j++){
            if (k%(i*j)==0&&k/(1ll*i*j)<=z){
                ll l = 1ll*k/(1ll*i*j);
                ans = max(ans,1ll*(x-i+1)*(y-j+1)*(z-l+1));
            }
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll T;
    cin >> T;
    while (T --){
        solve();
    }
}