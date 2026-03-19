#include <bits/stdc++.h>

#define x first 
#define y second 

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    LL n, m, k;
    cin >> n >> m >> k;
    if (n * (n - 1) / 2 > k) {
        cout << "NO\n";
        return;
    }
    vector<LL> use(n);
    for (int i = 1;i <= n - 1;i ++) {
        
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}