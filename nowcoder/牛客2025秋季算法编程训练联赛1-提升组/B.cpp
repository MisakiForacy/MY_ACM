#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
using namespace std;
using LL = long long;

const LL MOD = 1e9 + 7;

void solve() {
    LL n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<LL> a(n + 1), p1(n + 1, 0), p2(n + 1, 0);
    for (int i = 1;i <= n;i ++) a[i] = s[i] - '0';
    for (int i = 1;i <= n;i ++) p1[i] = p1[i - 1] + (a[i] == 1);
    for (int i = 1;i <= n;i ++) p2[i] = p2[i - 1] + (a[i] == 0);
    int l = 0, ans = 0;
    for (int i = 1;i <= n;i ++) {
        while (p1[i] - p1[l] > k && p2[i] - p2[l] > k) l ++;
        ans = max(ans, i - l);
    }
    cout << ans << '\n';
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}