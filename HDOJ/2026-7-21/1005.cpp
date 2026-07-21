#include <bits/stdc++.h>

using namespace std;

using LL = long long;

int f(string s) {
    int k = 0;
    set<char> st;
    for (char c : s) st.insert(c);
    int m = st.size();
    int n = s.size();
    s = ' ' + s;
    vector<int> pi(n + 1);
    for (int i = 1;i <= n;i ++) {
        int len = pi[i - 1];
        while (len && s[i] != s[len]) {
            len = pi[len - 1];
        }
        pi[i] = len + (s[i] == s[len]);
    }
    vector<vector<int>> f(n + 1, vector<int> (m + 1, 0));
    for (int i = 1;i < n - 1;i ++) {
        for (int j = 0;j < m - 1;j ++) {
            char c = s[j];
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
    cin >> s;
    cout << f(s) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}