#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<map<int, int>> a(n + 1);
    for (int i = 1;i <= m;i ++) {
        int x, y, g;
        cin >> x >> y >> g;
        for (int i = 1;i <= g;i ++) {
            for (int j = 0;j < siz(p);j ++) {
                while (g % p[j] == 0) {
                    g /= p[j];
                    a[x][p[j]] ++;
                    a[y][p[j]] ++;
                }
            }
        }
    }    
    for (int i = 1;i <= q;i ++) {
        int x, y;
        cin >> x >> y;
        LL v1 = 1, v2 = 1;
        for (auto v : a[x]) v1 *= v;
        for (auto v : a[y]) v2 *= v;
        cout << __gcd(v1, v2) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}