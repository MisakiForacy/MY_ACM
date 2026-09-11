#include <bits/stdc++.h>

#define x first 

#define y second 

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

#define lowbit(x) ((x) & (-x))

using namespace std;

using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<LL> f(n + 1, 0), p(n + 1), use(n + 1), alls;
    vector<char> op(n + 1);
    map<LL, LL> val;
    for (int i = 1;i <= n;i ++) {
        cin >> op[i] >> p[i];
        alls.push_back(p[i]);
    }
    sort(all(alls));
    alls.erase(unique(all(alls)), alls.end());
    for (int i = 1;i <= n;i ++) {
        use[i] = lower_bound(all(alls), p[i]) - p.begin() + 1;
        val[use[i]] = p[i];
    }
    auto upd = [&](int x, int v) -> void {
        for (;x <= n;x += lowbit(x)) f[x] += v;
    };
    auto ask = [&](int x) -> LL {
        LL res = 0;
        for (;x;x -= lowbit(x)) res += f[x];
        return res;
    };
    auto getKth = [&](int k) {
        int l = 1, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            if (ask(mid) >= k)
                r = mid;
            else   
                l = mid + 1;
        }
        return l;
    };
    int tot = 0;
    for (int i = 1;i <= n;i ++) {
        if (op[i] == '+') {
            upd(use[i], 1);
            tot ++;
        } else {
            upd(use[i], -1);
            tot --;
        }
        
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}