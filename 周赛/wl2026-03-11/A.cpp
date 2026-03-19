#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    LL mi = n / k, mx = n / k + (n % k ? 1 : 0);
    int cnt = n % k;
    string use;
    for (int i = 1;i <= k;i ++) {
        for (int j = 1;j <= mi;j ++) {
            cout << char('a' + i - 1);
        }
    }
    for (int i = 1;i <= n % k;i ++) {
        cout << char('a' + i - 1);
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}