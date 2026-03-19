#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
using namespace std;
using LL = long long;

// 2 1 5 4 3

void solve() {
    int n;
    cin >> n;
    auto ask = [&](vector<int> v) -> vector<int> {
        vector<int> tmp;
        cout << "? ";
        cout << siz(v) << ' ';
        for (int x : v) {
            cout << x << ' ';
        }
        cout << '\n';
        int c, x;
        cin >> c;
        for (int i = 1;i <= c;i ++) {
            cin >> x;
            tmp.push_back(x);
        }
        return tmp;
    };
    int cur = 0, lst = -1;
    vector<int> nxt(n * n + 2, -1), p;
    auto getlen = [&]() -> int {
        int u = 0, len = 0;
        while (nxt[u] != -1) {
            u = nxt[u];
            len ++;
        }
        return len;
    };
    auto getlst = [&]() -> int {
        int u = 0;
        while (nxt[u] != -1) {
            u = nxt[u];
        }
        return u;
    };
    vector<int> used(n * n + 2, 0), vis(n * n + 2, 0);
    for (int i = 1;i <= n;i ++) {
        p.clear();
        cur = 0;
        for (int j = 1;j <= n * n + 1;j ++)
            if (!used[j]) 
                p.push_back(j);
        vector<int> pp = ask(p);
        for (int j = 0;j < siz(pp);j ++) {
            nxt[cur] = pp[j];
            cur = pp[j];
        // for (int i = 1;i <= n * n + 1;i ++) {
        //     cout << nxt[i] << ' ';
        // }
        // cout << '\n';
        }
        used[cur] = 1;
        if (lst != -1) nxt[cur] = lst;
        // cout << cur << 'x' << nxt[cur] << '\n';
        // cout << '\n';
        lst = cur;
        if (getlen() >= n + 1) break;
    }
    if (getlen() < n + 1) {
        for (int i = 1;i <= n * n + 1;i ++) {
            if (!used[i]) {
                nxt[getlst()] = i;
            }
        }
    }
    int u = 0, len = 0;
    cout << "! ";
    while (nxt[u] != -1 && len < n + 1) {
        len ++;
        u = nxt[u];
        cout << u << ' ';
    }
    cout << '\n';
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}