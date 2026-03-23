#include <bits/stdc++.h>

#define x first 
#define y second 

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = siz(s);
    reverse(all(t));
    s = ' ' + s;
    t = ' ' + t;
    vector<LL> p1(n + 1, 1), p2(n + 1, 0), p3(n + 1, 1), p4(n + 1, 0);
    vector<LL> ps(n + 2, 1), pt(n + 2, 1);
    ps[n + 1] = pt[n + 1] = 0;
    for (int i = 1;i <= n;i ++) {
        while (i - p1[i] >= 1 && i + p1[i] <= n && s[i - p1[i]] == s[i + p1[i]]) {
            ps[i - p1[i]] = max(ps[i - p1[i]], p1[i] * 2 + 1);
            p1[i] ++;
        }
        while (i - p2[i] >= 2 && i + p2[i] <= n && s[i - p2[i] - 1] == s[i + p2[i]]) {
            ps[i - p2[i] - 1] = max(ps[i - p2[i] - 1], (p2[i] + 1) * 2);
            p2[i] ++;
        }
        while (i - p3[i] >= 1 && i + p3[i] <= n && s[i - p3[i]] == s[i + p3[i]]) {
            pt[i - p3[i]] = max(pt[i - p3[i]], p3[i] * 2 + 1);
            p3[i] ++;
        }
        while (i - p4[i] >= 2 && i + p4[i] <= n && s[i - p4[i] - 1] == s[i + p4[i]]) {
            pt[i - p4[i] - 1] = max(pt[i - p4[i] - 1], (p4[i] + 1) * 2);
            p4[i] ++;
        }
    }
    vector<vector<LL>> f(n + 1, vector<LL> (n + 1, 0));
    // f[i][j] 表示s[1...i]和t[1...j]的最长公共子后缀长度
    LL ans = 0;
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= n;j ++) {
            f[i][j] = f[i - 1][j - 1] + (s[i] == t[j]);
            ans += f[i][j] * (ps[i + 1] + pt[j + 1] + 1);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}