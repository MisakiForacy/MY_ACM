#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

const LL inf = 1e15;

const int N = 1e6 + 10;

void solve() {
    LL n, k;
    cin >> n >> k;
    if ((k & 1) && k <= n) {
        cout << -1 << '\n';
    } else if (!(k & 1) && k - 1 <= n) {
        cout << -1 << '\n';
    } else {
        
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}