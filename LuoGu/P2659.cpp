#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    LL a, b;
    cin >> a >> b;
    auto cal = [&](LL x) -> LL {
        LL len = 0, Tp = x;
        vector<int> p;
        while (Tp) {
            len ++;
            p.push_back(Tp % 10);
            Tp /= 10;
        }
        p.push_back(0);
        reverse(all(p));
        // for (int i = 1;i <= len;i ++) cout << p[i];
        // cout << '\n';
        LL f[len + 1][10][2];
        memset(f, 0, sizeof(f));
        f[0][0][1] = 1;
        for (int t = 0;t <= 1;t ++) {
            for (int i = 1;i <= len;i ++) {
                if (t == 1) {
                    for (int j = 0;j < p[i];j ++) {
                        if (abs(j - p[i - 1]) != 1 || i - 1 == 0) {
                            f[i][j][0] += f[i - 1][p[i - 1]][1];
                        }
                    }
                    if (abs(p[i] - p[i - 1]) != 1 || i - 1 == 0) {
                        f[i][p[i]][1] += f[i - 1][p[i - 1]][1];
                    }
                } else {
                    for (int j = 0;j <= 9;j ++) {
                        for (int jj = 0;jj <= 9;jj ++) {
                            if (abs(j - jj) != 1 || i - 1 == 0) {
                                f[i][j][0] += f[i - 1][jj][0];
                            }
                        }
                    }
                }
            }
        }
        LL ans = 0;
        for (int i = 0;i <= 9;i ++) ans += f[len][i][0] + f[len][i][1];
        return ans;
    };
    cout << cal(b) - cal(a - 1) << '\n';
}