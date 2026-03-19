#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

mt19937_64 rnd(time(0));

LL rd() {
    LL L = 1, R = 9;
    // cout << L << ' ' << R << '\n';
    return L + rnd() % 9;
}

int main() {
    // for (int i = 1;i <= 100;i ++) {
    //     cout << rd() << '\n';
    // }
    // cout << rd() << '\n';
    auto get = [&](int x) -> LL {
        LL v = 0;
        for (int i = 1;i <= x;i ++) {
            v *= 10;
            v += rd();
        }
        return v;
    };
    auto g = [&](LL n) -> int {
        int cnt = 0;
        while (siz(to_string(n)) > 1) {
            cnt ++;
            LL m = 1;
            for (char c : to_string(n)) {
                m *= c - '0';
            }
            n = m;
        }
        return cnt;
    };
    auto f = [&](LL n) -> LL {
        LL m = 1;
        for (char c : to_string(n)) {
            m *= c - '0';
        }
        return m;
    };
    cout << f(27777789999999999) << '\n';
    vector<LL> use;
    while (siz(use) < 2) {
        // LL x = get();
        // if (g(x) >= 11) {
        //     if (siz(use) && f(x) == f(use[0])) continue;
        //     use.push_back(x);
        // }
        LL x;
        if (siz(use)) x = get(17);
        else          x = get(18);
        // if (g(x) >= 11) use.push_back(x);
        if (siz(use) == 0) {
            cout << g(x) << ' ' << x << '\n'; 
            if (g(x) >= 11) use.push_back(x);
        } else {
            if (g(x) >= 11) {
                cout << g(x) << ' ' << f(x) << ' ' << x << '\n'; 
                if (f(x) == f(use[0])) continue;
                else use.push_back(x);
            }
        }
    }
    for (auto x : use) cout << x << ',';
    cout << '\n';
    for (auto x : use) cout << f(x) << ',';
    cout << '\n';
}