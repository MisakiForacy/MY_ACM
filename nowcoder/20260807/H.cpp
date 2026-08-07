#include <bits/stdc++.h>

#define all(x) begin(x),end(x)

#define siz(x) ((int)x.size())

using namespace std;

using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> p(3 * n);
    for (int i = 0;i < 3 * n;i ++) p[i] = i;
    int cases = 0;
    do {
        int ok = 1;
        for (int i = 0;i < n;i ++) {
            int x = i * 3, y = x + 1, z = x + 2;
            if (p[z] == 0) { ok = 0; break;}
            if (p[x] % p[z] != p[y]) { ok = 0; break; }
        }
        int cnt = 0;
        if (ok) {
            cout << "Case : " << ++ cases << " : \n";
            for (int x : p) cout << x << " \n"[(++cnt) % 3 ? 0 : 1];
        }
    } while (next_permutation(all(p)));
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}