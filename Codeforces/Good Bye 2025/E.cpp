#include <bits/stdc++.h>

#define x first 
#define y second 

#define LOG 30

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

void solve() {
    int n;
    cin >> n;
    LL Mx = 0;
    auto ask = [&](int l, int r) -> LL {
        cout << "? " << l << ' ' << r << '\n';
        LL ret;
        cin >> ret;
        if (l == r) Mx = max(Mx, ret);
        return ret;
    };
    LL l = 1, r = n;
    LL Sm = ask(l, r);
    while (l < r) {
        LL Cur = l;
        for (int j = 20;j >= 0;j --) {
            LL Tmp = Cur + (1LL << j);
            if (Tmp >= r) continue;
            if (ask(l, Tmp) > Sm / 2) continue;
            Cur = Tmp;
        }
        LL L = Cur - l + 1, R = r - Cur;
        if (L <= R) r = Cur;
        else        l = Cur + 1;
        Sm = Sm / 2;
    }
    Mx = ask(l, r);
    cout << "! " << Mx << '\n';
}

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}