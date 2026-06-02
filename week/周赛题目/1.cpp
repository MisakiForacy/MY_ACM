#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void solve() {
    string s;
    cin >> s;
    int m, n = siz(s);
    cin >> m;
    vector<int> a(m + 1, 0);
    for (int i = 1;i <= m;i ++) cin >> a[i];
    map<char, int> mp; 
    for (char c : s) mp[c] ++;
    sort(all(s));
    s.erase(unique(all(s)), s.end());
    sort(all(s), greater());
    vector<char> ans(m + 1, ' ');
    int idx = 0;
    while (1) {
        int ok = 1;
        for (int i = 1;i <= m;i ++) if (ans[i] == ' ') ok = 0;
        if (ok) break;
        vector<int> use;
        for (int i = 1;i <= m;i ++) {
            if (ans[i] == ' ' && a[i] == 0) {
                use.push_back(i);
            }
        }
        while (mp[s[idx]] < siz(use)) idx ++;
        for (int x : use) ans[x] = s[idx];
        idx ++;
        for (int i = 1;i <= m;i ++) {
            if (ans[i] == ' ' && a[i] != 0) {
                for (int x : use) 
                    a[i] -= abs(x - i);
            }
        }
    }
    for (int i = 1;i <= m;i ++) cout << ans[i];
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}