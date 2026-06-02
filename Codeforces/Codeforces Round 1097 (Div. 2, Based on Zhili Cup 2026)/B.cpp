#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n), b, b1, c, c1;
    for (int i = 0;i < n;i ++) cin >> a[i];
    sort(all(a));
    LL mx = a.back();
    map<LL, LL> mp, mp1;
    for (int i = 0;i < n;i ++) mp[a[i]] ++, mp1[a[i]] ++;
    for (auto &[k, v] : mp) {
        if ((siz(b) && k - 1 != b.back()) || (!siz(b) && k != 0)) break;
        b.push_back(k);
        v --;    
    }
    for (auto &[k, v] : mp) {
        for (int i = 0;i < v;i ++) 
            b1.push_back(k);
    }
    sort(all(b1), greater());
    for (int i = 0;i < siz(b1);i ++) b.push_back(b1[i]);
    c.push_back(mx);
    mp1[mx] --;
    for (auto &[k, v] : mp1) {
        c.push_back(k);
        v --;
    }
    for (auto &[k, v] : mp1) {
        for (int j = 0;j < v;j ++) 
            c.push_back(k);
    }
    LL ans1 = 0, ans2 = 0;
    LL mex1 = 0, mex2 = 0;
    LL mx1 = 0, mx2 = 0;
    map<LL, LL> use1, use2;
    for (int i = 0;i < n;i ++) {
        use1[b[i]] ++, mx1 = max(mx1, b[i]);
        use2[c[i]] ++, mx2 = max(mx2, c[i]);
        while (use1.count(mex1)) mex1 ++;
        while (use2.count(mex2)) mex2 ++;
        ans1 += mx1 + mex1;
        ans2 += mx2 + mex2;
    }
    cout << max(ans1, ans2) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}
