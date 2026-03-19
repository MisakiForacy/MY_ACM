#include <bits/stdc++.h>

#define x first 
#define y second 

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

void solve() {
    int n, xa, ya, xb, yb;
    cin >> n;
    cin >> xa >> ya >> xb >> yb;
    vector<PLL> p(n);
    map<int, vector<int>> cal, raw;
    for (auto &[x, y] : p) 
        cin >> x >> y, cal[y].push_back(x), raw[x].push_back(y);
    for (auto &[k, v] : cal) sort(all(v)); 
    for (auto &[k, v] : raw) sort(all(v)); 
    for (int i = 0;i < n;i ++) { 
        
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}