#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> x(n,0);
    vector<ll> p(n,0);
    vector<ll> pre(n+1,0);
    for (int i=0;i<n;i++){
        cin >> x[i];
    }
    for (int i=0;i<n;i++){
        cin >> p[i];
    }
    for (int i=1;i<=n;i++){
        pre[i] = pre[i-1] + p[i-1];
    }
    ll q;
    cin >> q;
    for (int i=0;i<q;i++){
        ll l,r;
        cin >> l >> r;
        l = lower_bound(all(x),l)-x.begin();
        r = upper_bound(all(x),r)-x.begin();
        // cout << l << ' ' << r << '\n';
        cout << pre[r] - pre[l] << '\n';
    }
}