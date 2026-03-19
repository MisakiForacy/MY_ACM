#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PII = pair<LL, LL>;

const LL inf = 1e18 + 10;

void solve() {
    LL n;
    cin >> n;
    // if (__builtin_popcountll(n) == 1) {
    //     cout << -1 << '\n';
    //     return;
    // }
    vector<LL> a(n + 1);
    set<int> use;
    for (int i = 1;i <= n;i ++) use.insert(i);
    a[n] = 1;
    use.erase(1);
    for (int i = 2;i <= n - 1;i ++) {
        a[i] = i ^ 1;
        use.erase(a[i]);
    }
    a[1] = *use.begin();
    // if (n % 2 == 0) {
    //     int c = 1;
    //     while ((n ^ (1 << c)) >= n) c ++;
    //     swap(a[1], a[1 << c]);
    // }
    for (int i = 1;i <= n;i ++) cout << a[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}