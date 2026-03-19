#include <bits/stdc++.h>

#define x first 
#define y second 

#define LOG 30

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

void solve() {
    string s;
    cin >> s;
    int cnt = 0;
    if (s[0] == 'u') s[0] = 's', cnt ++;
    if (s.back() == 'u') s.back() = 's', cnt ++;
    int n = siz(s);
    for (int i = 0;i < n;i ++) {
        if (s[i] == 'u' && s[i - 1] == 'u') {
            s[i] = 's';
            cnt ++;
        }
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}