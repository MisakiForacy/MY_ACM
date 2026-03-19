#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

const int N = 2e5 + 10;
const LL inf = 1e18 + 1;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void solve() {
    int n;
    cin >> n;
    int ans = n;
    vector<LL> a(n + 1),dp(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    map<int, int> mp;
    for (int i = 1;i <= n;i ++) {
        if (mp.count(a[i] - 1)) {
            ans --;
        } else {
            mp.clear();
        }
        mp[a[i]] ++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}