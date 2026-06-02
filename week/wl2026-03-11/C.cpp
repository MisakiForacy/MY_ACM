#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    LL n, m;
    cin >> n >> m;
    if (n < m) swap(n, m);
    map<int, int> s1;
    s1[0] = n / 5;
    s1[1] = (n + 4) / 5;
    s1[2] = (n + 3) / 5;
    s1[3] = (n + 2) / 5;
    s1[4] = (n + 1) / 5;
    LL ans = 0;
    for (int i = 1;i <= m;i ++) {
        ans += s1[(5 - i % 5) % 5];
    }
    cout << ans << '\n';    
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}