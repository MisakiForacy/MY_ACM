#include <bits/stdc++.h>

#define x first 
#define y second 

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    LL x;
    cin >> x;
    auto d = [&](LL v) -> LL {
        LL S = 0;
        for (char c : to_string(v)) S += c - '0';
        return S;
    };
    // for (int x = 0;x <= 100;x ++){
    int cnt = 0;
    for (int i = 1;i <= 10000;i ++) {
        LL y = x + i;
        if (y - x == d(y)) {
            cnt ++;
        }
    }
    cout << cnt << '\n';
    // }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}