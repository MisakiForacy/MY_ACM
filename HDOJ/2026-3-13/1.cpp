#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

#define LOG 60

using namespace std;
using LL = long long;

const LL inf = 1e15;
const LL MOD = 1e9 + 7;

void solve() {
    LL x;
    cin >> x;
    LL mx = 1;
    for (LL i = sqrt(x);i >= 1;i --) {
        if (x % i == 0) {
            LL v = i;
            if (x - v != v) mx = max(mx, v);
            v = min(x / v, x - x / v);
            if (x - v != v) mx = max(mx, v);
        }
    }
    cout << mx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}