#include <bits/stdc++.h>

#define all(x) begin(x),end(x)

#define siz(x) ((int)x.size())

using namespace std;

using LL = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> val(n + 1), pos(n + 1);
    for (int i = 1;i <= n;i ++) {
        cin >> val[i];
        pos[val[i]] = i;
    }
    while (q --) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            cin >> x >> y;
            int a = val[x], b = val[y];
            swap(val[x], val[y]);
            pos[a] = y;
            pos[b] = x;
        } else {
            swap(val, pos);
        }
    }
    for (int i = 1;i <= n;i ++) cout << val[i] << ' ';
    cout << '\n';
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
