#include <bits/stdc++.h>

using namespace std;

using LL = long long;

// abbaabba
// bbaabbaa 

const int N = 100010;

int f[N];

int find(int x) {
    return (f[x] == x ? f[x] : f[x] = find(f[x]));
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (x < y) swap(x, y);
    f[x] = y;
}

void solve() {
    int n, d;
    cin >> n >> d;
    string s;
    cin >> s;
    s = ' ' + s;
    for (int i = 1;i <= n;i ++) f[i] = i;
    if (d) {
        for (int l = 1;l <= n;l ++) {
            int r = n - l + 1;
            for (int i = 1;i <= n - 1;i ++) {
                if (find(l) == find(r)) break;
                merge(l, r);
                l = (l + d - 1) % n + 1;
                r = (r + d - 1) % n + 1;
            }
        }
    } else { 
        int ans = 0;
        for (int l = 1;l <= n / 2;l ++) {
            if (s[l] != s[n - l + 1]) ans ++;
        }
        cout << ans << '\n';
        return;
    }
    int ans = 0;
    vector<int> cnt(n + 1, 0);
    vector<vector<int>> p(n + 1, vector<int> (26, 0));
    for (int i = 1;i <= n;i ++) p[find(i)][s[i] - 'a'] ++, cnt[find(i)] ++;
    for (int i = 1;i <= n;i ++) {
        if (cnt[i]) {
            int mx = 0;
            for (int j = 0;j < 26;j ++) {
                mx = max(mx, p[i][j]);
            }
            ans += cnt[i] - mx;
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
