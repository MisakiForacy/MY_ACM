#include <bits/stdc++.h>

using namespace std;

using LL = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    LL a, b;
    LL r = 2;
    cin >> a >> b;
    auto f = [&](auto f, LL a, LL b) -> int {
        if (b & 1) {
            return 0;
        }
        LL res = 0;
        res = f(f, b, a / 2) + 1;
        return res;
    };
    r += f(f, a, b);
    cout << r / 2 << ' ' << r % 2 << '\n';
}