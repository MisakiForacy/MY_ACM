#include <bits/stdc++.h>

#define x first 
#define y second 

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

const LL inf = 1e15;

void solve() {
    LL n, m;
    cin >> n >> m;
    LL v1, v2;
    auto cal = [&]() -> LL {
        if (n & 1) {
            LL v = ((n + 1) / 2) * ((m + 1) / 2);
            v += (n / 2) * (m / 2);
            return v;
        } else {
            LL h = n / 2 - 1;
            LL v = ((h + 1) / 2) * ((m + 1) / 2);
            v += ((h - 1) / 2) * (m / 2);
            return v * 2;
        }
    };
    v1 = cal();
    swap(n, m);
    v2 = cal();
    cout << max(v1, v2) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}