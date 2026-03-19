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
    LL n, x;
    cin >> n >> x;
    for (int i = 1;i <= n;i ++) {
        LL v;
        cin >> v;
        if (x > v) {
            cout << 1 << '\n';
            x = v;
        } else {
            cout << 0 << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}