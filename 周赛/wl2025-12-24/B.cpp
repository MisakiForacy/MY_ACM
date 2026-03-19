#include <bits/stdc++.h>
using namespace std;
using LL = long long;

vector<LL> p(20, 0), p10(20, 1);

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    LL base = 1;
    for (int i = 1; i <= 18;i ++) {
        p[i] = p[i - 1] + i * base * 9;
        base *= 10;
    }
    for (int i = 1; i <= 18;i ++) p10[i] = p10[i - 1] * 10;
    int T;
    cin >> T;
    while (T --) {
        LL k;
        cin >> k;
        auto cal1 = [&](LL v) -> LL {
            LL Sm = 0;
            for (LL d = 1; d <= 18;d ++) {
                LL L = p10[d - 1];
                if (L > v) break;
                LL R = min(v, p10[d] - 1);
                LL x = (R - L + 1) * (v + 1);
                LL y = (L + R) * (R - L + 1) / 2;
                Sm += d * (x - y);
            }
            return Sm;
        };
        // cout << cal1(6) << '\n';
        // cout << cal1(4) << '\n';
        // cout << cal1(56) << '\n';
        auto cal2 = [&](LL v) -> LL {
            LL Sm = 0;
            for (LL d = 1; d <= 18;d ++) {
                LL L = p10[d - 1];
                if (L > v) break;
                LL R = min(v, p10[d] - 1);
                Sm += d * (R - L + 1);
            }
            return Sm;
        };
        LL lo = 1, hi = 1e9;
        while (lo < hi) {
            LL Mid = (lo + hi) >> 1;
            if (cal1(Mid) < k) lo = Mid + 1;
            else hi = Mid;
        }
        LL use = k - cal1(lo - 1);
        // cout << lo << ' ' << use << '\n';
        LL Lo = 1, Hi = lo;
        while (Lo < Hi) {
            LL Mid = (Lo + Hi) >> 1;
            if (cal2(Mid) >= use) Hi = Mid;
            else Lo = Mid + 1;
        }
        LL pos = use - cal2(Lo - 1);
        LL len = p10[Lo];
        // cout << Lo << ' ' << pos << ' ' << len << '\n';
        if (pos < 1) pos = 1;
        if (pos > len) pos = len;
        pos = len - pos;
        LL Ans = (Lo / p10[pos]) % 10;
        cout << Ans << '\n';
    }
    return 0;
}