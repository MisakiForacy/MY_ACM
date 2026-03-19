#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve () {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0;i < n;i ++) cin >> a[i];
    sort(all(a));
    int ok = 1;
    for (int i = 0;i < n - 1;i ++) {
        if ((i & 1) && a[i] != a[i + 1]) ok = 0;
    }
    cout << (ok ? "YES\n" : "NO\n");
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}