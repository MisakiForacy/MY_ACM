#include <bits/stdc++.h>

#define x first 

#define y second 

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

void solve() {
    string s;
    cin >> s;
    auto cal = [&](LL val) -> map<LL, int> {
        map<LL, int> mp;
        for (LL i = 2;i * i <= val;i ++) {
            while (val % i == 0) {
                mp[i] ++;
                val /= i;
            }
        }
        if (val > 1) mp[val] ++;
        return mp;
    };
    LL val = 0;
    for (int i = 0;i < min(10, siz(s));i ++) {
        val *= 10;
        val += s[i] - '0';
    }
    map<LL, int> mp = cal(val);
    for (int i = 0;i < siz(s) - 10;i ++) {
        mp[2] ++, mp[5] ++;
    }
    // LL res = 1;
    cout << siz(mp) << '\n';
    for (auto [k, v] : mp) {
        cout << k << ' ' << v << '\n';
        // for (int j = 0;j < v;j ++) {
        //     res *= k;
        // }
        // cout << res << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}