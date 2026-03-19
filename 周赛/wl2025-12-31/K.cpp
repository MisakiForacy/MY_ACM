#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

struct node
{
    LL x, id;
    bool operator < (const node&T) const {
        return x < T.x;
    }
};


void solve() {
    int n, root;
    cin >> n;
    vector<int> c(n + 1);
    vector<vector<int>> G(n + 1);
    for (int i = 1;i <= n;i ++) {
        int p;
        cin >> p >> c[i];
        if (~p) {
            G[p].push_back(i);
        } else {
            root = i;
        }
    }
    vector<int> Ans;
    for (auto &v : G) sort(v.begin(), v.end());
    for (int i = 1;i <= n;i ++) {
        if (i == root) continue;
        if (c[i]) {
            int ok = 1;
            for (auto x : G[i]) {
                if (!c[x]) {
                    ok = 0;
                }
            }
            if (ok) Ans.push_back(i);
        }
    }
    if (siz(Ans)) {
        for (auto x : Ans) cout << x << ' ';
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve(); 
}