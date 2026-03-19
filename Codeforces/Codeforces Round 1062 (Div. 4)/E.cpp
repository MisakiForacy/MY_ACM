#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
using namespace std;
using LL = long long;

int N = 2e5 + 10;

vector<LL> p, s(N, 0);

const LL inf = 1e18;

void Euler() {
    s[1] = 1;
    for (int i = 2;i < N;i ++) {
        if (!s[i]) p.push_back(i);
        for (int j = 0;j < siz(p) && p[j] * i < N;j ++) {
            s[p[j] * i] = 1;
            if (i % p[j] == 0) break;
        }
    }
}

void solve() {
    LL n, k, x;
    cin >> n >> k >> x;
    vector<LL> a(n + 1, -1e10);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    sort(all(a));
    a.push_back(1e10);
    auto check = [&](LL v) -> int {
        LL cnt = 0;
        LL L = 0, R;
        for (int j = 1;j <= n;j ++) {
            if (a[j] - v >= 0 && a[j] - v >= a[j - 1] + v) {
                R = a[j] - v;
                cnt += R - L + 1;
            }
            if (a[j] + v <= x && a[j] + v <= a[j + 1] - v) {
                L = a[j] + v;
            }
        }
        if (L >= a[n]) cnt += x - L + 1;
        // cout << v << ' ' << cnt << '\n';
        return cnt >= k;
    };
    LL lo = 0, hi = x;
    while (lo < hi) {
        LL mid = lo + hi >> 1;
        if (check(mid)) lo = mid + 1;
        else hi = mid - 1;
    }
    if (!check(lo)) lo --;
    // cout << lo << '\n';
    LL L = 0, R, v = lo;
    vector<LL> p;
    map<LL, int> use;
    for (int j = 1;j <= n;j ++) {
        if (a[j] - v >= 0 && a[j] - v >= a[j - 1] + v) {
            R = a[j] - v;
            for (int i = L;i <= R;i ++) {
                if (use.count(i)) continue;
                use[i] = 1;
                p.push_back(i);
                if (siz(p) == k) break;
            }
        }
        if (a[j] + v <= x && a[j] + v <= a[j + 1] - v) {
            L = a[j] + v;
        }
        if (siz(p) == k) break;
    }
    if (L >= a[n] && siz(p) < k) {
        for (int i = L;i <= x;i ++) {
            if (use.count(i)) continue;
            use[i] = 1;
            p.push_back(i);
            if (siz(p) == k) break;
        }
    }
    for (LL x : p) cout << x << ' ';
    cout << '\n';
}

int main() {
    // Euler();
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}