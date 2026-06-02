#include <bits/stdc++.h>

#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

const int N = 1e5;

struct SegTree
{
    int tot, n, m, len;
    vector<int> sum, rt, ls, rs;
    vector<int> a, idx;
    SegTree (int _n) {
        sum.resize((_n << 5) + 1);
        rt.resize(_n + 1);
        ls.resize((_n << 5) + 1);
        rs.resize((_n << 5) + 1);
        a.resize(_n + 1);
    }
    int build(int l, int r) {
        int root = ++ tot;
        if (l == r) return root;
        int mid = l + r >> 1;
        ls[root] = build(l, mid);
        rs[root] = build(mid + 1, r);
        return root;
    }
    int upd = 
};

int main() {

}