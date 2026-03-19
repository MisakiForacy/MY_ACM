#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define lowbit(x) ((x) & (-x))

using namespace std;
using LL = long long;
using PII = pair<LL, LL>;

struct SegTree
{
    #define lc p << 1
    #define rc p << 1 | 1
    struct node
    {
        LL l, r, lazPut, lazflip, f, Mx;
    };
    vector<node> f; vector<LL> a;
    SegTree(int _n) { f.resize(_n << 2 | 3), a.resize(_n + 2);}
    void pushup(int p) {
        // f[p].Mx = max(f[lc].Mx, f[rc].Mx);
    }
    void pushdown(int p) {
        if (f[p].lazflip || f[p].lazPut) {

        }
    }
};

void solve() {
    
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}