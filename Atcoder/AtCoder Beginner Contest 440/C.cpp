#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

mt19937_64 rnd(time(0));

LL inf = 1e15;

void solve() {
    LL n, w, Ans = inf;
    cin >> n >> w;
    vector<LL> c(n + 1), p(2 * w, 0);
    for (int i = 1;i <= n;i ++) cin >> c[i];
    for (int i = 1;i <= n;i ++) p[i % (2 * w)] += c[i];
    LL V = 0;
    for (int i = 0;i < w;i ++) V += p[i];
    Ans = min(Ans, V);
    for (int s = 1; s < 2 * w;s ++) {
        V -= p[s - 1];
        V += p[(s + w - 1) % (2 * w)];
        Ans = min(Ans, V);
    }
    cout << Ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}