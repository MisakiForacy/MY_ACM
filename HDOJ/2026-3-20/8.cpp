#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

vector<int> s(50, 0), p;

void pri() {
    for (int i = 2;i <= 30;i ++) {
        if (!s[i]) p.push_back(i);
        for (int j = 0;j < siz(p) && i * p[j] <= 30;j ++) {
            s[i * p[j]] = 1;
            if (i % p[j] == 0) break;
        }
    }
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<map<LL, LL>> a(n + 1);
    for (int i = 1;i <= m;i ++) {
        LL x, y, g;
        cin >> x >> y >> g;
        for (int i = 1;i <= g;i ++) {
            for (int j = 0;j < siz(p);j ++) {
                LL cnt = 0;
                while (g % p[j] == 0) {
                    g /= p[j];
                    cnt ++;
                }
                a[x][p[j]] = max(a[x][p[j]], cnt);
                a[y][p[j]] = max(a[y][p[j]], cnt);
            }
        }
    }   
    vector<int> aa(n + 1, 1); 
    for (int i = 1;i <= n;i ++) {
        for (int j = 0;j < siz(p);j ++) {
            for (int t = 1;t <= a[i][p[j]];t ++) {
                aa[i] *= p[j];
            }
        }
        // cout << aa[i] << '\n';
    }
    // for (int i = 1;i <= n;i ++) cout << aa[i] << ' ';
    // cout << '\n';
    for (int i = 1;i <= q;i ++) {
        int x, y;
        cin >> x >> y;
        cout << __gcd(aa[x], aa[y]) << '\n';
    }
}

int main() {
    pri();
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}