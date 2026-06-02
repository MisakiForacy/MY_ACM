#include <bits/stdc++.h>

#define x first 
#define y second 

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

const LL inf = 1e15;

struct node
{
    LL v, w;
    bool operator < (const node&T) const {
        return w < T.w;
    }
};

void solve() {
    LL n, k;
    cin >> n >> k;
    vector<LL> a(n + 1), dp(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    dp[1] = a[1];
    for (int i = 2;i <= n;i ++) dp[i] = dp[i - 1] + a[i] / 2;
    for (int i = 2;i <= n;i ++) {
        
    }
    cout << dp[n] << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}