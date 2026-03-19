#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve() {
    int n, m = 0;
    cin >> n;
    map<int, vector<int>> asked;
    auto ask = [&](int k) -> vector<int> {
        if (asked.count(k)) return asked[k];
        cout << "? " << k << '\n';
        int len;
        cin >> len;
        vector<int> Tp(len);
        for (int i = 0;i < len;i ++) cin >> Tp[i];
        asked[k] = Tp;
        return Tp;
    };
    vector<int> L(n + 1, 0), R(n + 1, 0), cnt(n + 1, 0);
    for (int s = 1;s <= n;s ++) {
        L[s] = R[s - 1] + 1;
        R[s] = L[s];
        for (int j = 15;j >= 0;j --) {
            int Tp = R[s] + (1LL << j);
            vector<int> p = ask(Tp);
            if (!siz(p) || p[0] != s) continue;
            R[s] = Tp;
        }
        cnt[s] = R[s] - L[s] + 1;
    }
    vector<int> in(n + 1, 0);
    vector<vector<int>> g(n + 1, vector<int>(n + 1, 0));
    for (int s = 1;s <= n;s ++) {
        int pos = L[s] + 1;
        while (pos <= R[s]) {
            vector<int> p = ask(pos);
            int v = p[1];
            if (!g[s][v]) {
                g[s][v] = 1;
                m ++;
            }
            pos += cnt[v];
        }
    }
    cout << "! " << m << '\n';
    for (int u = 1;u <= n;u ++) {
        for (int v = 1;v <= n;v ++) {
            if (g[u][v]) cout << u << ' ' << v << '\n';
        }
    }
}

/*
3 -> 1 -> 2
1: 1
2: 1 2
3: 2
4: 3
5: 3 1
6: 3 1 2
*/

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}