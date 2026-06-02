#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    string ans = "";
    while (n > 3) {
        ans = '1' + ans;
        n -= 2;
    }
    if (n == 2) {
        ans = '1' + ans;
    } else if (n == 3) {
        ans = '7' + ans;
    }
    cout << ans << '\n';    
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}