#include <bits/stdc++.h>

using namespace std;

using LL = long long;

int f(string s, int m) {
    int k = 0;
    int n = s.size();
    vector<int> pi(n + 1);
    for (int i = 1;i < n;i ++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        pi[i] = j + (s[i] == s[j]);
    }
    s = ' ' + s;
    for (int i = n;i >= 1;i --) pi[i] = pi[i - 1];
    // for (int i = 1;i <= n;i ++) cout << pi[i] << ' ';
    // cout << '\n';
    vector<vector<int>> f(n + 1, vector<int> (m + 1, 0));
    for (int i = 1;i < n;i ++) {
        for (int j = 0;j < m;j ++) {
            char c = 'a' + j;
            int pos = i;
            while (pos > 0 && c != s[pos + 1]) {
                pos = pi[pos];
                k += 1;
            }
            if (c == s[pos + 1]) {
                f[i][j] = pos + 1;
            } else {
                f[i][j] = pos;
            }
        }
    }
    return k;
}

void solve() {
    string s;
    int m;
    cin >> s >> m;
    cout << f(s, m) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}