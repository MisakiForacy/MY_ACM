#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

const LL N = 1005;
const LL MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n, 0);
    for (int i = 0;i < n;i ++) cin >> p[i];
    if (count(all(p), 1) != 1) {
        cout << "NO\n";
        return;
    } else {
        int add = find(all(p), 1) - p.begin();
        int lst = 1;
        for (int i = 1;i < n;i ++) {
            int t = (i + add) % n;
            if (p[t] - lst >= 2) {
                cout << "NO\n";
                return;
            }
            lst = p[t];
        }
        cout << "YES\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}