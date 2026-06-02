#include <bits/stdc++.h>

#define x first 

#define y second 

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

const LL inf = 1e16;

const int N = 100010;

vector<vector<int>> pos(N), g(N);

void solve() {
    LL n, q;
    cin >> n >> q;
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;i ++) 
        cin >> a[i], pos[a[i]].push_back(i);
    for (int i = 1;i <= n;i ++) {
        
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T --) solve();
}