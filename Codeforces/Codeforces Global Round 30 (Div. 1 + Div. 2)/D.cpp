#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

const int N = 2e5;
const LL inf = 1e15;

void solve() {
    int n, kk;
    string s, t;
    cin >> n >> kk;
    cin >> s >> t;
    if (s[0] != t[0]) {
        cout << -1 << '\n';
        return;
    }
    map<int, vector<int>> pos;
    for (int i = 0;i < n;i ++) pos[s[i] - 'a'].push_back(i);
    vector<int> use(n), tmp(n);
    auto check = [&](int k) -> int {
        for (int i = 0;i < n;i ++) tmp[i] = -1;
        int lst = 0;
        for (int i = 0;i < n;i ++) {
            int L = max(0, i - k);
            int x = max(L, lst);
            auto it = lower_bound(all(pos[t[i] - 'a']), x);
            if (it == pos[t[i] - 'a'].end()) return 0;
            int pp = *it;
            if (pp > i) return 0;
            tmp[i] = pp;
            lst = pp;
        }
        return 1;
    };
    int lo = 0, hi = n, ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (check(mid)) {
            ans = mid;
            use = tmp;
            hi = mid - 1;
        } else lo = mid + 1;
        // cout << lo << ' ' << hi << ' ' << mid << '\n';
    }
    if (ans == -1 || ans > kk) {
        cout << -1 << '\n';
        return;
    }
    cout << ans << '\n';
    string cur = s;
    for (int r = 1;r <= ans;r ++) {
        string nxt = cur;
        for (int i = 1;i < n;i ++) {
            if (use[i] <= i - r) nxt[i] = cur[i-1];
            else nxt[i] = cur[i];
        }
        cout << nxt << '\n';
        cur = nxt;
    }
}

int main () {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}