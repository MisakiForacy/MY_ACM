#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve() {
    int n, l;
    cin >> n >> l;
    if (l == 1) l = 2;
    vector<int> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    map<int, int> Mp;
    deque<int> dq;
    LL Ans = 0, p = 0;
    for (int i = 1;i <= n;i ++) {
        if (siz(dq) && a[i] == dq.back()) {
            dq.clear();
            dq.push_back(a[i]);
            Mp.clear();
            p = 0;
        } else {
            dq.push_back(a[i]);
            if (siz(dq) >= l) {
                Mp[dq[p ++]] ++;
                Ans += (siz(dq) - l + 1) - Mp[a[i]];
            }
        }
    }
    cout << Ans << '\n';
}
// 5 4 4 3 3 2 2 1 1
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}