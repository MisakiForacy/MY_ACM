#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

const LL inf = 1e16;

void solve() {
    LL n, x, y;
    string s;
    cin >> n >> x >> y;
    cin >> s;
    s = ' ' + s;
    vector<LL> p(n + 1);
    for (int i = 1;i <= n;i ++) cin >> p[i];
    vector<LL> a(n + 1), b(n + 1);
    LL Ad = 0, Bd = 0;
    for (int i = 1;i <= n;i ++) { 
        if (s[i] - '0') {   // s = 1 , b > a
            b[i] = (p[i] + 2) / 2;
            a[i] =  p[i] - b[i];
            Ad += a[i];
        } else {
            a[i] = (p[i] + 2) / 2;
            b[i] =  p[i] - a[i];
            Bd += b[i];
        }
    }
    LL Sa = 0, Sb = 0;
    for (int i = 1;i <= n;i ++) Sa += a[i], Sb += b[i];
    int ok = 1;
    if (Sa + Sb > x + y) ok = 0;
    int v = 0;
    while (ok && (Sa > x || Sb > y)) {
        if (v) {
            ok = 0;
            break;
        }
        v = 1;
        if (Ad < Sa - x) ok = 0;
        else Ad -= Sa - x, Sb += Sa - x, Sa -= Sa - x;
        if (Bd < Sb - y) ok = 0;
        else Bd -= Sb - y, Sa += Sb - y, Sb -= Sb - y;
        // cout << Sa << ' ' << Sb << '\n';
    }
    
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T --) solve();
}