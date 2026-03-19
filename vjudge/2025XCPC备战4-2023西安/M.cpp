#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define x first 
#define y second  
using namespace std;
using LL = long long;

/*
2
4
8 2 7 10
6
9 6 5 3 4 8
*/

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n+1,0);
    vector<LL> pre(n+1,0);
    LL Min = INT_MAX;
    LL idx;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
        if (a[i] < Min){
            Min = a[i];
            idx = i;
        }
    }
    double ans1 = 1.0 * (pre[idx+1] - pre[0]) / (idx+1);
    double ans2 = 1.0 * (pre[n] - pre[idx-2]) / (n-(idx-2));
    double ans3 = 1.0 * (pre[n] - pre[0]) / n;
    cout << max({ans1,ans2,ans3}) << '\n';
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    cout << fixed << setprecision(20);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}