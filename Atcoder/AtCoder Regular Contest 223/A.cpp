#include <bits/stdc++.h>

#define all(x) begin(x),end(x)

#define siz(x) ((int)x.size())

using namespace std;

using LL = long long;

struct node
{
    __int128_t w, v;
};

void solve() {
    LL n, w;
    cin >> n >> w;
    vector<node> p(n);
    vector<__int128_t> prev(n), prew(n);
    __int128_t ans = 0;
    for (int i = 0;i < n;i ++) {
        LL ww, vv;
        cin >> ww >> vv;
        p[i].w = ww;
        p[i].v = vv;
        prew[i] = i ? prew[i - 1] + ww : ww;
        prev[i] = i ? prev[i - 1] + vv : vv;
    }
    for (int i = n - 1;i >= 0;i --) {
        if (prew[i] <= w) {
            ans += prev[i];
            break;
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