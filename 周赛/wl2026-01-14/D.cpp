#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;
using PII = pair<LL, LL>;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k + 1);
    for (int i = 1;i <= k;i ++) cin >> a[i];
    LL Ans = 0;
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            int x;
            cin >> x;
            int c = 0;
            if (a[1] == x) Ans += 1;
            vector<int> p(k + 1);
            for (int t = k;t >= 2;t --) {
                if (a[t] == x) c = -1, Ans += t;
                p[t] = a[t + c];
            }
            p[1] = x;
            a = p;
        }
    }
    cout << Ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}