#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    LL Sm = 0;
    for (int i = 2;i <= n;i ++) Sm += abs(a[i] - a[i - 1]);
    LL Mi = Sm;
    Mi = Sm - abs(a[2] - a[1]);
    for (int i = 3;i <= n;i ++) {
        LL V = Sm - abs(a[i - 1] - a[i - 2]) - abs(a[i] - a[i - 1]);
        V += abs(a[i] - a[i - 2]);
        Mi = min(Mi, V);
    }
    Mi = min(Mi, Sm - abs(a[n] - a[n - 1]));
    cout << Mi << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T --) solve();
}