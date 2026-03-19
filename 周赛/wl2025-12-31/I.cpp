#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1, 1e15);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    int Mx = 0;
    for (int i = 1;i <= n;i ++) {
        int len = 1;
        while  (i <= n && a[i] >= a[i - 1]) 
            i ++, len ++;
        Mx = max(Mx, len);
    }
    cout << Mx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve(); 
}