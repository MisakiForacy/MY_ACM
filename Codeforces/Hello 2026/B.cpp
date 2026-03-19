#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PII = pair<LL, LL>;

const int N = 200005;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<LL> a(n + 1);
    map<int, int> mp;
    for (int i = 1;i <= n;i ++) cin >> a[i], mp[a[i]] ++;
    LL need = n - k + 1;
    for (auto &[k, v] : mp) {
        need -= (v - 1);
        v = 1;
    }
    for (int i = n;i >= 0;i --) {
        if (need > 0) {
            if (need > mp[i]) {
                need -= mp[i];
                mp[i] = 0;
            } else {
                mp[i] -= need;
                need = 0;
            }
        }
    }
    for (int i = 0;i <= n + 1;i ++) {
        if (!mp[i]) {
            cout << i << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}