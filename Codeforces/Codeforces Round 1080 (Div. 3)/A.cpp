#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size()) 

#define x first 
#define y second 

using namespace std;
using LL = long long;

const int N = 2e5 + 10;
const LL inf = 1e18;

void solve() {
    int n;
    cin >> n;
    int _1 = 0, _67 = 0;
    for (int i = 1;i <= n;i ++) {
        int x;
        cin >> x;
        if (x == 1) _1 = 1;
        if (x == 67) _67 = 1;
    }
    cout << (_67 ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}