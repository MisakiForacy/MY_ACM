#include <bits/stdc++.h> 
#define all(x) begin(x),end(x) 
#define siz(x) ((int)x.size()) 

#define x first 
#define y second 

#define LOG 20 

using namespace std; 
using LL = long long; 

const LL inf = 1e15; 

void solve () { 
    int n;
    cin >> n;
    vector<LL> a(n), res(n);
    for (int i = 0;i < n;i ++) cin >> a[i];
    res = a;
    LL ans = 0;
    if (a[0] != -1 && a[n - 1] != -1) {
        ans = llabs(a[n - 1] - a[0]);
    } else {
        ans = 0;
        if (a[0] == -1 && a[n - 1] == -1) {
            res[0] = 0;
            res[n - 1] = 0;
        } else if (a[0] == -1) {
            res[0] = a[n - 1];
        } else {
            res[n - 1] = a[0];
        }
    }
    for (int i = 1;i + 1 < n;i ++) {
        if (res[i] == -1) res[i] = 0;
    }
    cout << ans << '\n';
    for (int i = 0;i < n;i ++) cout << res[i] << ' ';
    cout << '\n';
} 

int main () { 
    ios::sync_with_stdio(0); 
    cin.tie(0), cout.tie(0); 
    int T = 1; 
    cin >> T; 
    while (T --) solve (); 
} 