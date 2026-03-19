#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

const LL MOD = 998244353;

LL l, r;

LL solve() {
    // cin >> l >> r;
    auto cal = [&](string s) -> LL {
        LL use = 0;
        for (auto c : s) {
            use *= 10;
            use += c - '0';
        }
        string tp = to_string(use);
        reverse(all(tp));
        LL res = 0;
        for (auto c : tp) {
            res *= 10;
            res += c - '0';
        }
        return res;
    };
    if (siz(to_string(l)) != siz(to_string(r))) {
        string s1 = to_string(l), s2 = to_string(r), s3;
        LL mx = max(cal(s1), cal(s2));
        for (int i = 0;i < siz(s2);i ++) {
            string tp = s3;
            if (s2[i] > '0') {
                tp.push_back(s2[i] - 1);
                for (int j = i + 1;j < siz(s2);j ++) tp.push_back('9');
                mx = max(mx, cal(tp));
            }
            s3.push_back(s2[i]);
        }
        // cout << mx << '\n';
        return mx;
    } else {
        int k = siz(to_string(l));
        string tp1 = to_string(r), tp2 = to_string(l), tp3;
        int f = 0;
        for (int i = 0;i < k;i ++) {
            if (f) {
                tp3.push_back('9');
            } else {
                if (tp1[i] == tp2[i]) {
                    tp3.push_back(tp1[i]);
                } else {
                    f = 1;
                    tp3.push_back(tp1[i] - 1);
                }
            }
        }
        string s1 = tp1, s2 = tp2, s3 = tp3;
        // cout << max({cal(s1), cal(s2), cal(s3)}) << '\n';
        return max({cal(s1), cal(s2), cal(s3)});
    }
}

LL brute() {
    auto cal = [&](string s) -> LL {
        reverse(all(s));
        LL res = 0;
        for (auto c : s) {
            res *= 10;
            res += c - '0';
        }
        return res;
    };
    LL mx = 0;
    for (int i = l;i <= r;i ++) {
        mx = max(mx, cal(to_string(i)));
    }
    return mx;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        cin >> l >> r;
        cout << solve() << '\n';
        // cout << brute() << '\n';
    }
}