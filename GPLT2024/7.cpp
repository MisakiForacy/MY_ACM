#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    LL a, b, mx = 0;
    cin >> a >> b;
    map<int, vector<int>> mp;
    for (LL i = a;i <= b;i ++) {
        LL x = i, cnt = 0;
        while (x >= 10) {
            LL nx = 1;
            while (x) {
                nx *= x % 10;
                x /= 10;
            }
            cnt ++;
            x = nx;
        }
        mp[cnt].push_back(i);
        mx = max(mx, cnt);
    }
    cout << mx << '\n';
    for (int i = 0;i < siz(mp[mx]);i ++) 
        cout << mp[mx][i] << " \n"[i == siz(mp[mx]) - 1];
}

int main() {
    cout << fixed << setprecision(2);
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}