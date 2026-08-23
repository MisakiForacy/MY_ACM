#include <bits/stdc++.h>

using namespace std;

using LL = long long;

using PLL = pair<LL, LL>;

void solve() {
    LL n, k, s;
    cin >> n >> k >> s;
    __int128_t ss = s;
    vector<PLL> p(n);
    for (int i = 0;i < n;i ++) cin >> p[i].first >> p[i].second;
    sort(p.begin(), p.end());
    for (int i = 0;i < n;i ++) {
        while (ss < p[i].first && k) {
            k --;
            ss *= 2;
        }
        if (ss >= p[i].first) {
            ss += p[i].second;
        } else break;
    }
    while (k > 0) k --, ss *= 2;
    vector<LL> ans;
    while (ss) {
        ans.push_back(ss % 10);
        ss /= 10;
    }
    reverse(ans.begin(), ans.end());
    for (LL x : ans) cout << x;
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}