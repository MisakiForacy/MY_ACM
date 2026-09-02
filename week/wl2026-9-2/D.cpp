#include <bits/stdc++.h>

#define x first 

#define y second 

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

using PLL = pair<LL, LL>;

LL s[4];

void solve() {
    int n, k;
    cin >> n >> k;
    int a[k + 1];
    memset(a, 0, sizeof a);
    for (int i = 1;i <= n;i ++) {
        a[(i - 1) % k + 1] ++'' 
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}