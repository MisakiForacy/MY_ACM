#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
using LL = long long;
int main(){
    int n,b;
    cin >> n;
    vector<LL> a(n+1,0);
    map<LL,LL> mp;
    for (int i=1;i<=n;i++){
        cin >> a[i] >> b;
        mp[a[i]] = b;
    }
    sort(a.begin()+1,a.end());
    vector<LL> pre(n+1,0);
    LL ans = LLONG_MAX;
    for (int i=1;i<=n;i++){
        pre[i] += pre[lower_bound(all(a),a[i]-mp[a[i]])-begin(a)-1]+i-(lower_bound(all(a),a[i]-mp[a[i]])-begin(a));
        ans = min(ans,pre[i]);
    }
    cout << ans << '\n';
}