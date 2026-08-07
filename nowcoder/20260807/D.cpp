#include <bits/stdc++.h>

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

struct SegTree 
{
    #define lc p << 1
    #define rc p << 1 | 1
    struct node
    {
        int l, r, laz, sum;
        node() { l = 0, r = 0, laz = 0, sum = 0; }
    };
    vector<node> f; vector<int> a;
    SegTree (int _n) {
        f.resize(_n << 2 | 3);
        a.resize(_n + 1);
    }
    void build(int l, int r, int p) {
        f[p].l = l, f[p].r = r;
        if (l == r) {
            
        }
    }
};

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), posa(n + 1), posb(n + 1), use(n + 1, 0);
    for (int i = 0;i < n;i ++) cin >> a[i], posa[a[i]] = i + 1;
    for (int i = 0;i < n;i ++) cin >> b[i], posb[b[i]] = i + 1;
    int i = 0, j = 0;
    auto case1 = [&](int i, int j) -> int {
        // 两者都在x前面
        // 去删相对位置差较小的那一项
        if (posa[a[i]] < posa[x] && posb[a[i]] < posb[x] && posa[b[j]] < posa[x] && posb[b[j]] < posb[x]) {
            if (abs(posa[a[i]] - posb[a[i]]) < abs(posa[b[j]] - posb[b[j]])) {
                use[a[i]] = 1;
                return 1;
            } else {
                use[b[j]] = 1;
                return 2;
            }
        }
        return 0; 
    };
    auto case2 = [&](int i, int j) -> int {
        // 假如其中某一项会在x后面出现，则删除均在x前方出现的那一项
        if (posa[a[i]] < posa[x] && posb[a[i]] < posb[x]) {
            use[a[i]] = 1;
            return 1;
        }
        if (posa[b[j]] < posa[x] && posb[b[j]] < posb[x]) {
            use[b[j]] = 1;
            return 2;
        }
        return 0;
    };
    // auto case3 = [&](int i, int j) -> int {
    //     // 剩余情况即为两项都在x后面出现，则允许删除任意项，该操作都不会直接导致无解
        
    // };
    while (i < n && j < n) {
        while (use[a[i]]) i ++;
        while (use[b[j]]) j ++;
        if (a[i] == b[j] && (a[i] != x || i != n - 1 || j != n - 1)) {
            cout << "NO\n";
            return;
        }
        if (case1(i, j)) {
            if (case1(i, j) == 1) {
                i ++;

            } else {
                j ++;

            }
        } else if (case2(i, j)) {
            if (case2(i, j)) {
                i ++;

            } else {
                j ++;

            }
        } else {
            // 考虑两者都存在在x后面出现，那就随便删
            use[a[i]] = 1;
            i ++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}