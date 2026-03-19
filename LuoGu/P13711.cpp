#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int main() {
    int n, k;
    cin >> n >> k;
    int a[n + 1][n + 1];
    memset(a, 0, sizeof a);
    int cnt = 0;
    auto valid = [&](int x, int y) -> bool {
        return (1 <= x && x <= n && 1 <= y && y <= n);
    };
    for (int i = 1;i <= n;i += 5) {
        for (int j = i;j <= i + n - 1;j ++) {
            int x = (j - 1) % n + 1;
            int y = j - i + 1;
            cout << x << ' ' << y << '\n';
            string s;
            cin >> s;
            if (s == "hit") {
                for (int v = 0;v < 4;v ++) {
                    int nx = x, ny = y, len = 1;
                    while (valid(nx + dx[v], ny + dy[v]) && len < 5) {
                        nx += dx[v], ny += dy[v], len += 1;
                        cout << nx << ' ' << ny << '\n';
                        cin >> s;
                    }
                }
            }
        }
    }
}