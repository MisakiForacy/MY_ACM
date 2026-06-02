#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<LL> p(n + 1);
    map<LL, vector<int>> mp;
    for (int i = 1;i <= n;i ++) {
        cin >> p[i];
        mp[p[i]].push_back(i);
    }
    LL cnt = 0;
    for (int d = 1;d <= n;d ++) {
        for (int i = 1;i <= sqrt(d);i ++) {
            if (d % i == 0) {
                int x = i, y = d / i;
                if (x == y) {
                    for (auto id : mp[x]) {
                        if (id - d >= 1 && p[id - d] == y) cnt ++;
                    }
                    continue;
                }
                if (siz(mp[x]) < siz(mp[y])) {
                    for (auto id : mp[x]) {
                        if (id - d >= 1 && p[id - d] == y) cnt ++;
                        if (id + d <= n && p[id + d] == y) cnt ++;
                    }
                } else {
                    for (auto id : mp[y]) {
                        if (id - d >= 1 && p[id - d] == x) cnt ++;
                        if (id + d <= n && p[id + d] == x) cnt ++;
                    }
                }
            }
        }
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}