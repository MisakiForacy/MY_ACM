#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    s = s, t = t;
    auto cal = [&](string s1, string s2) -> int {
        int cnt = 0;
        for (int i = 0;i < m;i ++) {
            while (s1[i] != s2[i]) {
                if (s1[i] == '9') s1[i] = '0';
                else s1[i] += 1;
                cnt ++;
            }
        }
        return cnt;
    };
    int Mi = 1000000;
    for (int i = 0;i <= n - m;i ++) {
        Mi = min(Mi, cal(t, s.substr(i, m)));
    }
    cout << Mi << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}