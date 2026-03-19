#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size()) 

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

const int N = 2e5 + 10;
const LL inf = 1e18;
const LL MOD = 1e9 + 7;
 
struct node
{
    LL a, b, c;
};

void solve() {
    int n;
    cin >> n;
    vector<node> p(n + 1);
    vector<vector<int>> g1(n + 1), g2(n + 1);
    vector<int> in1(n + 1, 0), in2(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> p[i].a >> p[i].b >> p[i].c;
    auto dx = [&](node A, node B) -> bool {
        LL na, nb, nc;
        na = A.a - B.a;
        nb = A.b - B.b;
        nc = A.c - B.c;
        if (na == 0 && nb == 0) return 0;
        return nb * nb - 4 * na * nc >= 0;
    };
    auto cmp = [&](node A, node B) -> int {
        return A.c > B.c;
    };  
    for (int i = 1;i <= n;i ++) {
        for (int j = i + 1;j <= n;j ++) {
            if (!dx(p[i], p[j])) {
                if (cmp(p[i], p[j])) {
                    g1[j].push_back(i);
                    g2[i].push_back(j);
                    in1[i] ++;
                    in2[j] ++;
                } else {
                    g1[i].push_back(j);
                    g2[j].push_back(i);
                    in1[j] ++;
                    in2[i] ++;
                }
            }
        }
    }
    vector<int> dpl(n + 1, 1), dpr(n + 1, 1);
    dpl[0] = dpr[0] = 0;
    queue<int> q1, q2;
    for (int i = 1;i <= n;i ++) {
        if (in1[i] == 0) q1.push(i);
        if (in2[i] == 0) q2.push(i);
    }
    auto topo = [&](int f) -> void {
        queue<int> q = f ? q1 : q2;
        vector<int> dp(n + 1, 1);
        dp[0] = 0;
        while (siz(q)) {
            auto u = q.front();
            q.pop();
            for (int v : (f ? g1[u] : g2[u])) {
                dp[v] = max(dp[v], dp[u] + 1);
                if (!(-- (f ? in1[v] : in2[v]))) q.push(v);
            }
        }
        (f ? dpl : dpr) = dp;
    };
    topo(0), topo(1);
    for (int i = 1;i <= n;i ++) cout << dpl[i] + dpr[i] - 1 << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}