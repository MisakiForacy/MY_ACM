#include <bits/stdc++.h>

#define x first 
#define y second

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

void solve() {
    int n, p, k;
    cin >> n >> p >> k;
    map<string, LL> mp;
    LL Sm = 0, Tot = 0;
    for (int i = 1;i <= n;i ++) {
        string x; int t;
        cin >> x >> t;
        mp[x] = t;
        Tot += t;
    }
    vector<string> use;
    LL Mx = 1e8;
    for (int i = 1;i <= k;i ++) {
        string s;
        cin >> s;
        use.push_back(s);
        Mx = min(Mx, mp[s]);
        Sm += mp[s];
    }
    if (Tot > Mx * p) {
        cout << -1 << '\n';
    } else {
        LL lo = 1, hi = Mx;
        auto check = [&](LL x) -> LL {
            if (Tot > x * p) return 0;
            return 1;
        };
        while (lo < hi) {
            LL Mid = lo + hi >> 1;
            if (check(Mid)) hi = Mid;
            else lo = Mid + 1;
        }
        cout << lo << ' ' << Mx << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}