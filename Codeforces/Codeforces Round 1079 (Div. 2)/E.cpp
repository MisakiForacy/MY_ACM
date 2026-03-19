#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    map<int, vector<int>> asked;
    auto ask = [&](int x) -> vector<int> {
        if (asked.count(x)) return asked[x];
        cout << "? " << x << '\n';
        int N;
        cin >> N;
        vector<int> Tp(N);
        for (int i = 0;i < N;i ++) cin >> Tp[i];
        asked[x] = Tp;
        return Tp;
    };
    const int MAXK = (1 << 30);

    vector<int> L(n + 1), R(n + 1), cnt(n + 1);
    int curL = 1;
    for (int s = 1;s <= n;s ++) {
        L[s] = curL;
        int lo = curL, hi = MAXK + 1;
        while (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            vector<int> p = ask(mid);
            if (!siz(p) || p[0] != s) hi = mid;
            else lo = mid;
        }
        R[s] = lo;
        cnt[s] = R[s] - L[s] + 1;
        curL = R[s] + 1;
    }

    int m = 0;
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
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= n;j ++) {
            if (g[i][j]) cout << i << ' ' << j << '\n';
        }
    }
}

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}