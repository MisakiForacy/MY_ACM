#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

const LL inf = 1e15;
const int N = 2e5 + 10;

const LL MOD = 998244353;

void solve () {
    int n, x;
    cin >> n;
    for (int i = 1;i <= n;i ++) {
        cin >> x;
        for (int j = 1;j <= n;j ++) {
            if (j == i) 
                cout << (x + 1) % MOD << ' ';
            else 
                cout << x << ' ';
        }
        cout << '\n';
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve ();
}