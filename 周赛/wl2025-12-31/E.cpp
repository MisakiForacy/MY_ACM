#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int need = n * m / 2;
    int N = n & 1, M = m & 1, f = 0, K = k;
    if (M) swap(n, m), f = 1, K = need - k;
    else K = k;
    vector<vector<int>> p(n + 1, vector<int> (m + 1, 0));
    N = n & 1, M = m & 1;
    auto get = [&](int x, int y) -> int {
        int ret = 0;
        cout << x << ' ' << y << ':';
        while (ret == x || ret == y) {
            ret ++;
            ret %= 26;
        }
        cout << ret << '\n';
        return ret;
    };
    if (N) {
        int line = m / 2;
        if (K < line) {
            cout << "NO\n";
            return;
        }
        K -= line;
        int d = 2;
        for (int i = 1;i <= m;i += 2) p[1][i] = p[1][i + 1] = get(p[0][i], p[1][i - 1]);
        // for (int i = 1;i <= m;i ++) cout << p[1][i] << ' ';
        // cout << '\n';
        while (K) {
            if (K & 1) {
                cout << "NO\n";
                return;
            }
            if (K >= line * 2) {
                for (int i = 1;i <= m;i += 2) p[d][i] = p[d][i + 1] = get(p[d][i - 1], p[d - 1][i]);
                d ++;
                for (int i = 1;i <= m;i += 2) p[d][i] = p[d][i + 1] = get(p[d][i - 1], p[d - 1][i]);
                d ++;
                K -= line * 2;
            } else {
                for (int i = 1;i <= K / 2;i += 2) p[d][i] = p[d][i + 1] = get(p[d][i - 1], p[d - 1][i]);
                d ++;
                for (int i = 1;i <= K / 2;i += 2) p[d][i] = p[d][i + 1] = get(p[d][i - 1], p[d - 1][i]);
                d ++;
                K = 0;
            }
        }
        for (int i = 1;i <= n;i ++) {
            for (int j = 1;j <= m;j ++) {
                if (!p[i][j]) {
                    cout << i << ' ' << j << '\n';
                    p[i][j] = p[i + 1][j] = get(p[i - 1][j], p[i][j - 1]);
                }
            }
        }
    } else {
        int line = m / 2;
        int d = 1;
        while (K) {
            if (K & 1) {
                cout << "NO\n";
                return;
            }
            if (K >= line * 2) {
                for (int i = 1;i <= m;i += 2) 
                    p[d][i] = p[d][i + 1] = get(p[d][i - 1], p[d - 1][i]);
                d ++;
                for (int i = 1;i <= m;i += 2) 
                    p[d][i] = p[d][i + 1] = get(p[d][i - 1], p[d - 1][i]);
                d ++;
                K -= line * 2;
            } else {
                for (int i = 1;i <= K / 2;i += 2) p[d][i] = p[d][i + 1] = get(p[d][i - 1], p[d - 1][i]);
                d ++;
                for (int i = 1;i <= K / 2;i += 2) p[d][i] = p[d][i + 1] = get(p[d][i - 1], p[d - 1][i]);
                d ++;
                K = 0;
            }
        }
        cout << "OK\n";
        for (int i = 1;i <= n;i ++) {
            for (int j = 1;j <= m;j ++) {
                if (!p[i][j]) {
                    cout << i << ' ' << j << '\n';
                    p[i][j] = p[i + 1][j] = get(p[i][j - 1], p[i - 1][j]);
                }
            }
        }  
    }
    cout << "YES\n";
    if (f) {
        for (int j = 1;j <= m;j ++) {
            for (int i = 1;i <= n;i ++) {
                cout << char('a' + (p[i][j] % 26));
            }
            cout << '\n';
        }
    } else {
        for (int i = 1;i <= n;i ++) {
            for (int j = 1;j <= m;j ++) {
                cout << char('a' + (p[i][j] % 26));
            }
            cout << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve(); 
}