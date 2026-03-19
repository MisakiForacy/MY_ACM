#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define lowbit(x) ((x) & (-x))

using namespace std;
using LL = long long;
using PII = pair<LL, LL>;

const LL N = 1e6 + 100;

int f[N];

void upd(int x, int n) {
    for (;x <= 2 * n + 100;x += lowbit(x)) f[x] += 1;
}

int qry(int x) {
    int Sm = 0;
    for (;x;x -= lowbit(x)) Sm += f[x];
    return Sm;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<int> pA(n + 1, 0), pB(n + 1, 0), v(n + 1, 0);
    for (int i = 1;i <= n;i ++) pA[i] = pA[i - 1] + (s[i] == 'A'), pB[i] = pB[i - 1] + (s[i] == 'B');
    LL Ans = 0;
    for (int i = n;i >= 0;i --) {
        v[i] = pB[i] - pA[i] + n + 10;
        Ans += qry(v[i] - 1);
        upd(v[i], n);
    }
    cout << Ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}