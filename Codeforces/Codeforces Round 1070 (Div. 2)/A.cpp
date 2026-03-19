#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0), Mx(n + 2, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n;i ++) Mx[i] = max(a[i], Mx[i - 1]);
    int Cnt = 0;
    for (int i = 1;i <= n;i ++) {
        if (a[i] < Mx[i - 1]) 
            Cnt ++;
    }
    cout << Cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T --) solve();
}