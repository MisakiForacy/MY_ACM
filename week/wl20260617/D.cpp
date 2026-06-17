#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n + 1][n + 1];
        memset(a, 0, sizeof(a));
        a[n / 2 + 1][n / 2 + 1] = 1;
        queue<pair<int, int>> q;
        int sx = n / 2 + 1, sy = n / 2 + 1;
        q.push({sx, sy});
        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            for (int k = 0;k < 4;k ++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (abs(nx - sx) + abs(ny - sy) > n / 2) continue;
                if (a[nx][ny]) continue;
                a[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
        int l = 1, r = 2;
        for (int i = 1;i <= n;i ++) {
            for (int j = 1;j <= n;j ++) {
                if (a[i][j]) {
                    a[i][j] = l;
                    l += 2;
                } else {
                    a[i][j] = r;
                    r += 2;
                }
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
    }   
}