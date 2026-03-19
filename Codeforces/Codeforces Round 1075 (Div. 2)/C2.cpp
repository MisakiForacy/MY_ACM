#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PII = pair<LL, LL>;

const LL inf = 1e18 + 10;
const LL MOD = 1e9 + 7;

void solve() {
    LL n;
    cin >> n;
    vector<LL> a(n + 1);
    a[n] = 1;
    for (int i = 1;i <= n - 1;i ++) a[i] = i ^ a[n];
    for (int i = 1;i <= n;i ++)
        cout << a[i] << ' ';
    cout << '\n';    
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}