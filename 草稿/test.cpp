#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

const LL inf = 1e15;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> p(n + 1, vector<int> (m + 1));
    vector<vector<int>> a(n + 1, vector<int> (m + 1));
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            char c; cin >> c;
            p[i][j] = (c == 'w');
            a[i][j] = p[i][j];
        }
    }
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
        }
    }
    int l = 0, r = m, u = 0, d = n;
    while (p[n][l + 1] - p[n][0] - p[0][l + 1] + p[0][0] == 0) l ++;
    while (p[n][m] - p[n][r - 1] - p[0][m] + p[0][r - 1] == 0) r --;
    while (p[u + 1][m] - p[u + 1][0] - p[0][m] + p[0][0] == 0) u ++;
    while (p[n][m] - p[d - 1][m] - p[n][0] + p[d - 1][0] == 0) d --;
    l ++, u ++;
    if ((r - l) < (d - u)) {
        int lok = 1, rok = 1;
        for (int i = u + 1;i <= d - 1;i ++) {
            if (a[i][l]) lok = 0;
            if (a[i][r]) rok = 0;
        }  
        if (r - l == 0) (m - l > l - 1 ? rok = 1: lok = 1);
        while ((r - l) < (d - u) && lok && l > 1) l --;
        while ((r - l) < (d - u) && rok && r < m) r ++;
    }
    if ((r - l) > (d - u)) {
        int dok = 1, uok = 1;
        for (int i = l + 1;i <= r - 1;i ++) {
            if (a[d][i]) dok = 0;
            if (a[u][i]) uok = 0;
        }   
        if (d - u == 0) (n - d > d - 1 ? dok = 1 : uok = 1);
        while ((r - l) > (d - u) && uok && u > 1) u --;
        while ((r - l) > (d - u) && dok && d < n) d ++;
    }
    int ok = 1;
    if (r - l != d - u) ok = 0;
    for (int i = l;i <= r;i ++) if (!a[u][i]) a[u][i] = 2;
    for (int i = l;i <= r;i ++) if (!a[d][i]) a[d][i] = 2;
    for (int j = u;j <= d;j ++) if (!a[j][l]) a[j][l] = 2;
    for (int j = u;j <= d;j ++) if (!a[j][r]) a[j][r] = 2;
    for (int i = u + 1;i <= d - 1;i ++) {
        for (int j = l + 1;j <= r - 1;j ++) {
            if (a[i][j]) ok = 0;
        }
    }
    if (!ok) {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            cout << (a[i][j] ? a[i][j] == 1 ? 'w' : '+' : '.');
        }
        cout << '\n';
    }
}