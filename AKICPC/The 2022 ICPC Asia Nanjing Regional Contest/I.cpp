#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
using namespace std;
using LL = long long;

/*
6
7
1 1 1 -1 1 1 -1
4
1 0 -1 0
4
0 -1 -1 0
1
0
2
0 0
1 
-1
*/

void solve() {
    string s;
    cin >> s;
    map<char, int> mp;
    for (char c : s) {
        mp[c] ++;
    }
    int ans = siz(s);
    for (auto [k, v] : mp) ans = min(ans, siz(s) - v);
    cout << ans << '\n'; 
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.tix", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}