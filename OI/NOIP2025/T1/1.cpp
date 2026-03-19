#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second

using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

const LL inf = 1e15;

void solve() {
    LL n, m;
    cin >> n >> m;
    vector<PLL> p(n);
    for (auto &[x, y] : p) cin >> x >> y;
    LL Sm = inf;
    sort(all(p));
    for (auto &[x, y] : p) {
        if (x + y <= Sm) {
            Sm = x + y;
        }
    }
    LL S = 0, Ans = 0, Cnt = 0;
    Ans = m / Sm * 2;
    for (auto &[x, y] : p) {
        S += x, Cnt += 1;
        if(S > m) break;
        LL Val = (m - S) / Sm * 2 + Cnt;
        Ans = max(Ans, Val);
    }
    cout << Ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}