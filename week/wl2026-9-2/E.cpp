#include <bits/stdc++.h>

#define x first 

#define y second 

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

using PLL = pair<LL, LL>;

LL qmi(LL x, LL k) {
    LL res = 1;
    while (k) {
        if (k & 1) res *= x;
        x = x * x;
        k >>= 1;
    }
    return res;
}

LL S(LL n) {
    LL res = 0;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

void solve() {
    LL a, b, c;
    cin >> a >> b >> c;
    vector<LL> ans;   
    for (int s = 1;s <= 100;s ++) {
        LL x = b * qmi(s, a) + c;
        if (x > 0 && x < 1e9 && s == S(x)) ans.push_back(x);
    }
    sort(all(ans));
    cout << siz(ans) << '\n';
    for (LL x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}