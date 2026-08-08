#include <bits/stdc++.h>

#define all(x) begin(x),end(x)

#define siz(x) ((int)x.size())

using namespace std;

using LL = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    int a[n + 1];
    memset(a, 0, sizeof a);
    set<int> pos;
    LL ans = 0;
    while (q --) {
        int op, x;
        cin >> op;
        if (op == 1) {
            cin >> x;
            ans ^= a[x];
            a[x] ++;
            ans ^= a[x];
            pos.insert(x);
        } else {
            vector<int> tp;
            for (int x : pos) {
                ans ^= a[x];
                a[x] --;
                ans ^= a[x];
                if (a[x] == 0) tp.push_back(x);
            }
            for (int x : tp) {
                // cout << "E : " << x << '\n';
                pos.erase(x);
            }
        }
        cout << ans << '\n';
    }
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
    int n, q;
    cin >> n >> q;
    int a[n + 1];
    memset(a, 0, sizeof a);
    set<int> pos;
    LL ans = 0;
    while (q --) {
        int op, x;
        cin >> op;
        if (op == 1) {
            cin >> x;
            ans ^= a[x];
            a[x] ++;
            ans ^= a[x];
            pos.insert(x);
        } else {
            vector<int> tp;
            for (int x : pos) {
                ans ^= a[x];
                a[x] --;
                ans ^= a[x];
                if (a[x] == 0) tp.push_back(x);
            }
            for (int x : tp) {
                // cout << "E : " << x << '\n';
                pos.erase(x);
            }
        }
        cout << ans << '\n';
    }
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
