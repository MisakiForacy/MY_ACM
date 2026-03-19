#include <bits/stdc++.h>
#define all(x) being(x),end(x)
using namespace std;
using LL = long long;

mt19937_64 rng(time(0));
LL exgcd(LL a, LL b, LL &x, LL &y){
    if (!b){
        x = 1, y = 0;
        return a;
    }
    LL d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

void solve() {
    LL A, B, C, x;
    cin >> A >> B >> C >> x;
    LL a, b;
    LL g = exgcd(A - B, B, a, b);
    if (C - x == 0) {
        cout << "Yes\n";
        return;
    }
    if (g == 0) {
        cout << "No\n";
        return;
    }
    if ((C - x) % g) {
        cout << "No\n";
        return;
    }
    LL d = (C - x) / g;
    // cout << g << ' ' << a * d << ' ' << b * d << '\n';
    if (a < 0 || b < 0) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
}

int main() {
    // cout << 6 % (-2) << '\n';
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}