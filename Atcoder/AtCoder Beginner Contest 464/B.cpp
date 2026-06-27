#include <bits/stdc++.h>

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    for (int i = 0;i < n;i ++) {
        for (int j = 0;j < m;j ++) {
            char c; cin >> c;
            a[i][j] = c == '.';
        }
    }
    int l = 0, r = m;
    int u = 0, d = n;
    auto cal1 = [&]() -> int {
        int ok = 1;
        for (int i = l;i < r;i ++) {
            if (!a[u][i]) ok = 0;
        }
        if (ok) u ++;
        return ok;
    };  
    auto cal2 = [&]() -> int {
        int ok = 1;
        for (int i = l;i < r;i ++) {
            if (!a[d - 1][i]) ok = 0;
        }
        if (ok) d --;
        return ok;
    };
    auto cal3 = [&]() -> int {
        int ok = 1;
        for (int i = u;i < d;i ++) {
            if (!a[i][l]) ok = 0;
        }
        if (ok) l ++;
        return ok;
    };
    auto cal4 = [&]() -> int {
        int ok = 1;
        for (int i = u;i < d;i  ++) {
            if (!a[i][r - 1]) ok = 0;
        }
        if (ok) r --;
        return ok;
    };
    while (1) {
        int ok = 0;
        ok = max(ok, cal1());
        ok = max(ok, cal2());
        ok = max(ok, cal3());
        ok = max(ok, cal4());
        // cout << ok << '\n';
        // cout << l << ' ' << r << ' ' << d << ' ' << u << '\n';
        if (!ok) break;
    }   
    for (int i = u;i < d;i ++) {
        for (int j = l;j < r;j ++) {
            cout << (a[i][j] ? '.' : '#');
        }
        cout << '\n';
    }
}

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}