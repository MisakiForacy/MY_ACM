#include <bits/stdc++.h>
#define x first 
#define y second 
using namespace std;
using LL = long long;

void solve() {
    double x0, y0;
    cin >> x0 >> y0;
    int n, k;
    cin >> n >> k;
    auto getd = [&](int x, int y) -> int {
        if (x > 0 && y > 0) return 1;
        if (x < 0 && y > 0) return 2;
        if (x < 0 && y < 0) return 3;
        if (x > 0 && y < 0) return 4;
        if (x == 0 && y > 0) return 5;
        if (y == 0 && x < 0) return 6;
        if (x == 0 && y < 0) return 7;
        if (y == 0 && x > 0) return 8;
        return 9;
    };
    vector<LL> p(10); 
    vector<pair<LL, LL>> v;
    for (int i = 1;i <= n;i ++) {
        int x, y;
        cin >> x >> y;
        p[getd(x, y)] ++;
        v.push_back({x, y});
    }
    auto getk = [&](LL x, LL y) -> double {
        if (x0 - x == 0) return 1e18;
        return (y0 - y) / (x0 - x); 
    };
    auto getb = [&](LL x, LL y) -> double {
        return y - getk(x, y) * x;
    };
    auto cal1 = [&]() -> double {
        double l = 1e18, r = -1e18;
        for (auto [x, y] : v) {
            int dd = getd(x, y);
            if (dd == 1 || dd == 5 || dd == 2) {
                double kk = getk(x, y);
                if (kk == 1e18) {
                    l = min(l, x0);
                    r = max(r, x0);
                    continue;
                }
                double bb = getb(x, y);
                double xx = -(bb / kk);
                l = min(l, xx);
                r = max(r, xx);
            }
        }
        return r - l;
    };
    auto cal2 = [&]() -> double {
        double l = 1e18, r = -1e18;
        for (auto [x, y] : v) {
            int dd = getd(x, y);
            if (dd == 3 || dd == 7 || dd == 4) {
                double kk = getk(x, y);
                if (kk == 1e18) {
                    l = min(l, x0);
                    r = max(r, x0);
                    continue;
                }
                double bb = getb(x, y);
                double xx = -(bb / kk);
                l = min(l, xx);
                r = max(r, xx);
            }
        }
        return r - l;
    };
    auto cal3 = [&]() -> double {
        double l = 1e18, r = -1e18;
        for (auto [x, y] : v) {
            int dd = getd(x, y);
            if (dd == 2 || dd == 6 || dd == 3) {
                double kk = getk(x, y);
                if (kk == 0) {
                    l = min(l, y0);
                    r = max(r, y0);
                    continue;
                }
                double bb = getb(x, y);
                double xx = bb;
                l = min(l, xx);
                r = max(r, xx);
            }
        }
        return r - l;
    };
    auto cal4 = [&]() -> double {
        double l = 1e18, r = -1e18;
        for (auto [x, y] : v) {
            int dd = getd(x, y);
            if (dd == 1 || dd == 4 || dd == 8) {
                double kk = getk(x, y);
                if (kk == 0) {
                    l = min(l, y0);
                    r = max(r, y0);
                    continue;
                }
                double bb = getb(x, y);
                double xx = bb;
                l = min(l, xx);
                r = max(r, xx);
            }
        }
        return r - l;
    };
    int a1 = p[1] + p[2] + p[5];
    int a2 = p[3] + p[4] + p[7];
    int a3 = p[2] + p[3] + p[8];
    int a4 = p[1] + p[4] + p[6];
    int cur = getd(x0, y0);
    double ans;
    if (cur == 1) {
        if (a1 > k && a4 > k) {
            cout << -1 << '\n';
            return;
        } else {
            ans = 1e18;
            if (a1 <= k) ans = min(ans, cal2());
            if (a4 <= k) ans = min(ans, cal3()); 
        }
    } else if (cur == 2) {
        if (a1 > k && a3 > k) {
            cout << -1 << '\n';
        } else {
            ans = 1e18;
            if (a1 <= k) ans = min(ans, cal2());
            if (a3 <= k) ans = min(ans, cal4()); 
        }
    } else if (cur == 3) {
        if (a3 > k && a2 > k) {
            cout << -1 << '\n';
        } else {
            ans = 1e18;
            if (a2 <= k) ans = min(ans, cal1());
            if (a3 <= k) ans = min(ans, cal4()); 
        }
    } else if (cur == 4) {
        if (a4 > k && a2 > k) {
            cout << -1 << '\n';
        } else {
            ans = 1e18;
            if (a2 <= k) ans = min(ans, cal1());
            if (a4 <= k) ans = min(ans, cal3()); 
        }
    } else if (cur == 5) {
        if (a1 > k && a3 > k && a4 > k) {
            cout << -1 << '\n';
        } else {
            ans = 1e18;
            if (a1 <= k) ans = min(ans, cal2());
            if (a4 <= k) ans = min(ans, cal3()); 
            if (a3 <= k) ans = min(ans, cal4()); 
        }
    } else if (cur == 6) {
        if (a3 > k && a2 > k && a1 > k) {
            cout << -1 << '\n';
        } else {
            ans = 1e18;
            if (a1 <= k) ans = min(ans, cal2());
            if (a2 <= k) ans = min(ans, cal1()); 
            if (a3 <= k) ans = min(ans, cal4());
        } 
    } else if (cur == 7) {
        if (a2 > k && a3 > k && a4 > k) {
            cout << -1 << '\n';
        } else {
            ans = 1e18;
            if (a4 <= k) ans = min(ans, cal3());
            if (a2 <= k) ans = min(ans, cal1()); 
            if (a3 <= k) ans = min(ans, cal4());
        }
    } else if (cur == 8) {
        if (a2 > k && a1 > k && a4 > k) {
            cout << -1 << '\n';
        } else {
            ans = 1e18;
            if (a1 <= k) ans = min(ans, cal2());
            if (a2 <= k) ans = min(ans, cal1()); 
            if (a4 <= k) ans = min(ans, cal3());
        }
    } else if (cur == 9) {
        if (min({a1, a2, a3, a4}) > k) {
            cout << -1 << '\n';
        } else {
            ans = 1e18;
            if (a1 <= k) ans = min(ans, cal2());
            if (a2 <= k) ans = min(ans, cal1()); 
            if (a3 <= k) ans = min(ans, cal4());
            if (a4 <= k) ans = min(ans, cal3());
        }
    }
    cout << ans << '\n';
}

int main() {
    cout << fixed << setprecision(6);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}