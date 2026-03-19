#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

const LL N = 1e6 + 5;

void solve() {
    int n;
    cin >> n;
    set<int> st;
    vector<vector<int>> a(n + 1);
    vector<vector<int>> tp(n + 1);
    for (int i = 1;i <= n;i ++) {
        int l;
        cin >> l;
        map<int, int> use;
        for (int j = 1;j <= l;j ++) {
            int x;
            cin >> x;
            tp[i].push_back(x);
        }
        for (int t = l - 1;t >= 0;t --) {
            int x = tp[i][t];
            if (!use[x]) a[i].push_back(x), use[x] = 1;
        }
    }
    vector<int> cur, use(n + 1, 0);
    map<int, int> use1;
    vector<int> p;
    for (int t = 1;t <= n;t ++) {
        int idx = -1;
        vector<int> Mi;
        for (int i = 1;i <= n;i ++) {
            if (use[i]) continue;
            vector<int> Tp;
            for (int j = 0;j < siz(a[i]);j ++) {
                if (!use1[a[i][j]]) Tp.push_back(a[i][j]);
            }
            if (idx == -1 || Tp < Mi) {
                Mi = Tp;
                idx = i;
            }
        }
        use[idx] = 1;
        p.push_back(idx);
        for (int i = 0;i < siz(Mi);i ++) {
            cur.push_back(Mi[i]);
            use1[Mi[i]] = 1;
        }
    }
    deque<int> res;
    reverse(all(p));
    for (int x : p) {
        cout << x << ' ';
        for (int i = 0;i < siz(tp[x]);i ++) {
            if (find(all(res), tp[x][i]) != res.end()) {
                res.erase(find(all(res), tp[x][i]));
                res.push_front(tp[x][i]);
            } else {
                res.push_front(tp[x][i]);
            }
        }
    }
    cout << '\n';
    for (int x : res) cout << x << ' ';
    cout << '\n';
    for (int x : cur) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}