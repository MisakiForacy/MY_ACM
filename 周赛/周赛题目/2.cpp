#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n, m, l;
    cin >> n >> m >> l;
    vector<LL> a(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    int need = n;
    deque<LL> p;
    for (int i = 1;i <= min(m, need + 1);i ++) p.push_back(0);
    int idx = 1;
    for (int i = 1;i <= l;i ++) {
        sort(all(p));
        p[0] += 1;
        if (idx <= n && i == a[idx]) {
            sort(all(p));
            p.pop_back();
            idx ++;
            need --;
            while (siz(p) < min(m, need + 1)) p.push_back(0);
        }
    }
    cout << p.front() << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}