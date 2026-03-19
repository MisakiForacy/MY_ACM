#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

mt19937_64 rnd(time(0));

LL inf = 1e15;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    sort(all(a));
    for (int i = 1;i <= q;i ++) {
        LL x, y;
        cin >> x >> y;
        int id = upper_bound(all(a), x) - a.begin() - 1;
        LL Low = x - id, Up;
        LL lo = x, hi = x + inf;
        if (x != *lower_bound(all(a), x)) Low -= 1;
        auto check = [&](LL v) -> int {
            int idx = upper_bound(all(a), v) - a.begin() - 1;
            Up = v - idx;
            return Up - Low >= y;
        };
        while (lo < hi) {
            LL Mid = lo + hi >> 1;
            if (check(Mid)) hi = Mid;
            else lo = Mid + 1;
        }
        cout << lo << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}