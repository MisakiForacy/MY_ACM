#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

#define LOG 60

using namespace std;
using LL = long long;

const LL inf = 1e15;
const LL MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    LL q;
    cin >> q;
    vector<LL> ans;
    vector<vector<int>> op(q + 1, vector<int> (3));
    for (int i = 1;i <= q;i ++) {
        cin >> op[i][0];
        if (op[i][0] == 1) {
            cin >> op[i][1] >> op[i][2];
        } else {
            cin >> op[i][1];
        }
    }
    map<int, int> del, chg;
    for (int i = q;i >= 1;i --) {
        if (op[i][0] == 3) {
            del[op[i][1]] = 1;
        } else if (op[i][0] == 2) {
            int v = op[i][1];
            if (!del[v]) {
                if (chg.count(v)) v = chg[v];
                ans.push_back(v);
            }
        } else {
            int vv = op[i][2];
            if (del[op[i][1]] && !del[vv]) {
                del[op[i][1]] = 0;
            } else if (del[vv]) {
                del[op[i][1]] = 1;
            }
            int v = vv;
            chg[op[i][1]] = v;
            if (chg.count(v)) chg[op[i][1]] = chg[v];
        }
    }
    for (int i = n;i >= 1;i --) {
        int v = a[i];
        if (!del[v]) {
            if (chg.count(v)) v = chg[v];
            ans.push_back(v);
        }
    }
    reverse(all(ans));
    for (int x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}