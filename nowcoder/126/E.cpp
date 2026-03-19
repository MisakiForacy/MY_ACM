#include <bits/stdc++.h>

#define x first 
#define y second

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

void solve() {
    LL x, a, b, c;
    cin >> x >> a >> b >> c;
    LL v = x, Mi = 1e18;
    LL Sm = 0;
    auto cal = [&](LL V) -> LL {
        LL L = 1005, R = 1011;
        LL pp = 14;
        LL Mi = 1e18;
        while (pp --) {
            if (V >= R);
            else if (L <= V && V < R) {
                Mi = 0;
            } else {
                LL use = L - V;
                LL cnt = use / c;
                LL Val = cnt * c + V;
                if (Val < L) cnt += 1;
                Val = cnt * c + V;
                if (L <= Val && Val < R) {
                    Mi = min(Mi, cnt);
                }
            }
            L *= 10, R *= 10;
        }
        return Mi;
    };
    for (;v >= 0;v /= 10, Sm += a) {
        LL Tmp = Sm + cal(v) * b;
        Mi = min(Mi, Tmp);
        if (!v) break;
    }
    cout << Mi << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}