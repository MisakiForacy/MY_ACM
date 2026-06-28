#include <bits/stdc++.h>

#define all(x) begin(x),end(x)

#define siz(x) ((int)x.size())

using namespace std;

using LL = long long;

struct node
{
    __int128_t w, v;
    bool operator < (const node&T) const {
        // LL t1 = v / w, t2 = T.v / T.w;
        // v / w > Tv / Tw
        if (v * T.w != T.v * w) return v * T.w < T.v * w;
        return w > T.w;
    };
};

void solve() {
    LL n, w;
    cin >> n >> w;
    vector<node> p(n);
    for (int i = 0;i < n;i ++) {
        LL ww, vv;
        cin >> ww >> vv;
        p[i].w = ww;
        p[i].v = vv;
    }
    sort(all(p));
    __int128_t ans = 0;
    for (int i = 0;i < n;i ++) {
        if (w >= p[i].w) {
            ans += p[i].v;
            w -= p[i].w;
        }
    }
    string s;
    while (ans) {
        s += ans % 10 + '0';
        ans /= 10;
    }
    reverse(all(s));
    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}