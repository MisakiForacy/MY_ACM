#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s, t;
    cin >> s;
    int n = s.size(), q;
    s = ' ' + s;
    vector<vector<int>> p(26, vector<int> (n + 2, n + 1));
    for (int i = 1;i <= n;i ++) p[s[i] - 'a'][i] = i;
    for (int i = 0;i < 26;i ++) 
        for (int j = n;j >= 0;j --) 
            p[i][j] = min(p[i][j + 1], p[i][j]);
    cin >> q;
    while (q --) {
        cin >> t;
        int px = 0;
        for (char c : t) {
            px += 1;
            if (px > n) break;
            px = p[c - 'a'][px];
        }
        cout << (px <= n ? "Yes\n" : "No\n");
    }
}