#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

const LL inf = 1e15;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> f(n + 1);
    for (int i = 1;i <= n;i ++) f[i] = i;
    auto find = [&](auto find, int x) -> int {
        return (f[x] == x ? x : f[x] = find(find, f[x]));
    };
    auto merge = [&](int x, int y) -> void {
        x = find(find, x);
        y = find(find, y);
        if (x == y) return;
        if (x < y) swap(x, y);
        f[x] = y;
    };
    for (int i = 1;i <= m;i ++) {
        int x, y, z;
        cin >> x >> y >> z;
        merge(x, y);
    }
    set<int> p;
    for (int i = 1;i <= n;i ++) {
        p.insert(find(find, i));
    }
    cout << siz(p) << '\n';
}