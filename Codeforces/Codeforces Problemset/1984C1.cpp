#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
void solve(){
    ll n,idx,mi;
    mi = inf;
    cin >> n;
    vector<ll>a(n+1),pre(n+1,0);
    for (int i=1;i<=n;i++){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
        if (pre[i] <= mi){
            mi = pre[i];
            idx = i;
        }
    }
    pre[idx] = abs(pre[idx]);
    for (int i=idx+1;i<=n;i++){
        pre[i] = pre[i-1] + a[i];
    }
    cout << pre[n] << '\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}