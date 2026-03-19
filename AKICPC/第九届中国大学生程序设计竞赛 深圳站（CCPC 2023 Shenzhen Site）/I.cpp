#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)
using namespace std;
// using LL = long long;

using LL = __int128_t;

LL input() {
    string s;
    cin >> s;
    LL res = 0;
    for (int i = 0; i < siz(s);i ++) {
        res *= 10;
        res += s[i] - '0';
    }
    return res;
}

void print(LL x) {
   if (x > 9) {
       print(x / 10);
   }
   putchar(x % 10 + '0');
}

LL qmi(LL a, LL k) {
    // print(a), cout << ' ';
    // print(k), cout << ' ';
    LL res = 1;
    while (k) {
        if (k % 2 == 1) res = res * a;
        a = a * a;
        k /= 2;
    }
    // print(res), cout << ' ';
    return res;
}

LL msqrt(LL x) {
    LL cur = 0;
    for (int j = 62;j >= 0;j --) {
        LL v = cur + (1LL << j);
        if (v * v <= x) cur = v;
    }
    return cur;
}

void solve() {
    LL n, k;
    n = input(), k = input();
    // cin >> n >> k;
    int ans = 0, Len = 0;
    for (int i = 1;i <= 1e7 + 10;i ++) {
        if (qmi(i, k) - qmi(i - 1, k) > n) {
            Len = i;
            break;
        }
    }
    auto check = [&](LL l, LL r) -> int {
        LL v = qmi(r, k) - qmi(l, k);
        return v <= n;
    };
    for (LL i = 1;i <= Len + 1;i ++) {
        LL lo = i, hi = Len + 1,ef=lo;
        while (lo < hi) {
            LL mid = (lo + hi) / 2;
            if (check(i, mid)) ef=mid,lo = mid+1;
            else hi = mid - 1;
        }
        // if (check(i, lo)) lo -= 1;
        LL y = qmi(ef, k) - qmi(i, k);
        // cout << i << '-' << lo << '\n';
        // cout << qmi(i, k) << '=' << qmi(lo, k) << '\n';
        // cout << "* "; print(qmi(lo, k));cout << '\n';
        // cout << "* "; print(qmi(i, k));cout << '\n';
        if (y == n) ans ++;
    }
    cout << ans << '\n';
}

/*
3
7 3
15 4
31 5
*/

int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    // print(msqrt(4));
    int T = 1;
    cin >> T;
    while (T --) solve();
}