#include <bits/stdc++.h>

using namespace std;

using LL = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    LL a, b, p = 0;
    double r = 1;
    cin >> a >> b;
    auto f = [&](auto f, LL a, LL b) -> void {
        if (b & 1) {
            return 1;
        }
    };
    f(f, a, b);
    cout << int(r) << ' ' << p << '\n';
}