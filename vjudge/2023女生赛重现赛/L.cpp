#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
#define nl cout << '\n';
#define debug(x) cerr << #x << ':' << x << ' '
#define x first
#define y second
using namespace std;
using LL = long long;

const int N = 2e5 + 10;
const LL inf = 1e15;

mt19937_64 rng(time(0));

struct node
{
    int i, j, op, a, b, d, v;
};


void fxy_ac() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> A(n + 1, 0);
    vector<node> p(m);
    for (int s = 0;s < m;s ++) {
        int i, j, op, a, b, d, v;
        cin >> i >> j >> op >> a >> b >> d >> v;
        p[s] = {i, j, op, a, b, d, v};
    } 
    LL ans = 0;
    auto dfs = [&](auto dfs, int s) -> void {
        if (s == n + 1) {
            // for (int i = 1;i <= n;i ++) {
            //     cout << A[i] << ' ';
            // }
            // cout << '\n';
            LL val = 0;
            for (int t = 0;t < m;t ++) {
                int i = p[t].i;
                int j = p[t].j;
                int op = p[t].op;
                int a = p[t].a;
                int b = p[t].b;
                int d = p[t].d;
                int v = p[t].v;
                if (op == 0) {
                    if (a * A[i] + b * A[j] <= d) {
                        val += v;
                    }
                } else {
                    if (a * A[i] + b * A[j] >= d) {
                        val += v;
                    }
                }
            }
            ans = max(ans, val);
            return;
        } 
        for (int i = 0;i <= k;i ++) {
            A[s] = i;
            dfs(dfs, s + 1);
        }
    };
    dfs(dfs, 1);
    cout << ans << '\n';
}

void brute() {

}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        fxy_ac();
        // brute();
    }
}