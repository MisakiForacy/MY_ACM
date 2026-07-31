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
    int cnt_ = 0;
    for (int k = 0;k <= 1;k ++) {
        for (int l = 1;l <= n;l ++) {
            int ll = (l + k * d - 1) % n + 1;
            int rr = (n - l + 1 + k * d - 1) % n + 1;
            merge(ll, rr);
        }
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
