#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int Diff(map<ll,ll>mp, map<ll,ll>cop){
    int diff = 0;
    for (auto [k,v]:mp){
        if (v > cop[k]){
            diff += v - cop[k];
        }
    }
    return diff;
}
void solve(){
    int n,m,k;
    int ans = 0;
    cin >> n >> m >> k;
    vector<ll>a(n+1),b(m+1);
    map<ll,ll> mp,cop;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=m;i++){
        cin >> b[i];
        mp[b[i]] ++;
    }
    for (int i=1;i<=m;i++){
        cop[a[i]] ++;
    }
    int diff = Diff(mp,cop);
    if (m - diff >= k) ans ++;
    // cout << diff << '\n';
    for (int i=m+1;i<=n;i++){
        if (mp[a[i-m]]>=cop[a[i-m]]) diff ++;
        cop[a[i-m]] --;
        if (cop[a[i]]<mp[a[i]]) diff --;
        cop[a[i]] ++;
        // cout << diff << '\n';
        if (m - diff >= k) ans ++;
    }
    cout << ans << '\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        solve();
    }
}