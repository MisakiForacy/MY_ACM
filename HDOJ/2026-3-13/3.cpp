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
    LL x, y;
    cin >> x >> y;
    if (x & 1) swap(x, y);
    if ((x & 1) && (y & 1)) {
        cout << (x + 1) / 2 + y / 2 << '\n';
    } else if ((y & 1)) {
        cout << x / 2 + y / 2 + 1 << '\n';
    } else {
        cout << x / 2 + y / 2 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}