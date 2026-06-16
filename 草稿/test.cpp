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
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            char c;
            cin >> c;
            p[i][j] = (c == 'w');
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
    while (p[n][m] - p[d - 1][m] - p[])
}