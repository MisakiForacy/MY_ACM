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
    reverse(all(t));
    s = ' ' + s;
    t = ' ' + t;
    vector<int> r1(n + 1, 1), r2(n + 1, 1);
    for (int i = 1;i <= n;i ++) {
        while (i - r1[i] >= 1 && i + r1[i] <= n && s[i - r1[i]] == s[i + r1[i]]) r1[i] ++;
        while (i - r2[i] >= 1 && i + r2[i] <= n && s[i - r2[i]] == s[i + r2[i]]) r2[i] ++;
    }
    vector<vector<int>> f(n + 1, vector<int> (n + 1, 0));
    // f[i][j] 表示s[1...i]和t[1...j]的最长公共子后缀长度
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= n;j ++) {
            f[i][j] = f[i - 1][j - 1] + (s[i] == t[j]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}