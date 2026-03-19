#include <bits/stdc++.h>
using namespace std;
using LL = long long;

mt19937_64 rnd(time(0));

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1, 0), vis(n + 1, 0), dp(n + 1, 0);
    for (int i = 0;i < n;i ++) cin >> a[i];
    for (int i = 0;i < n;i ++) dp[i] = (x - (a[i] + i) + n) % n;
    dp[x] = 0;
    
}   

void brute() {
    cout << 200000 << ' ' << 199999 << '\n';
    for (int i = 1;i <= 2e5;i ++) {
        cout << rnd() % 200000 << ' ';
    }
    cout << '\n';
}

int main() {
    // freopen("in.txt", "r", stdin);
    freopen("in.txt", "w", stdout);
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        // solve();
        brute();
    }
}