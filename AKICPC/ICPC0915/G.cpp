#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
bool check(ll mid,vector<ll> a){
    vector<ll> pre(n+1,0);
    for (int i=1;i<=n;i++){
        if (mid <= a[i]){
            a[i] = 1;
        } else{
            a[i] = -1;
        }
        pre[i] = pre[i-1] + a[i];
    }
    vector<vector<int>> mp(n+1,vector<int>(n+1,0));
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            mp[i][j] = (pre[j] - pre[i-1] > 0?1:-1);
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            mp[i][j] += mp[i-1][j] + mp[i][j-1];
        }
    }
    // for (int )
}
int main(){
    cin >> n;
    vector<ll> a(n+1,0);
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    ll lo = 0, hi = 1e9+1;
    while (lo <= hi){
        ll mid = (lo + hi) / 2;
        if (check(mid,a)) hi = mid - 1;
        else lo = mid + 1;
    }
    cout << lo << '\n';
}