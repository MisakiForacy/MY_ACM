#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

mt19937_64 rnd(time(0));

void solve () {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a (n + 1, vector<int> (n + 1, 0));
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= n;j ++) {
            char c;
            cin >> c;
            a[i][j] = c == '#';
        }
    }
    unordered_map<bitset<100>, int> mp;
    for (int i = 1;i <= n - m + 1;i ++) {
        for (int j = 1;j <= n - m + 1;j ++) {
            bitset<100> p;
            p.reset();
            int cnt = -1;
            for (int ii = i;ii <= n && ii - i < m;ii ++) {
                for (int jj = j;jj <= n && jj - j < m;jj ++) {
                    cnt ++;
                    p.set(cnt, a[ii][jj]);
                }
            }
            mp[p] ++;
        }
    }
    cout << siz(mp) << '\n';
} 

int main () {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}