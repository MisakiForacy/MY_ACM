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
    int n, k, d;
    cin >> n >> k;
    d = k + 1;
    vector<LL> a(n + 1), c(n + 1, 0);
    map<int, vector<int>> mp;
    map<int, int> cnt;
    for (int i = 1;i <= n;i ++) 
        cin >> a[i], mp[a[i]].push_back(i);
    for (int i = 1;i <= k;i ++) {
        int ok = 0;
        for (auto &[kk, v] : mp) {
            if (siz(v)) {
                c[v.back()] = i;
                v.pop_back();
                cnt[i] ++;
                ok = 1;
            }
        }
        if (!ok) {d = i; break;}
    }
    for (int i = d;i <= k;i ++) {
        int ok = 0;
        for (int j = 1;j <= n;j ++) {
            if (cnt[c[j]] > 1) {
                cnt[c[j]] -= 1;
                c[j] = i;
                ok = 1;
                break;
            }
        }
        if (!ok) {
            cout << "NO\n";
            return;
        }
    }
    int ok = 1;
    for (int i = 1;i <= n;i ++) if (!c[i]) ok = 0;
    if (ok) {
        cout << "YES\n";
        for (int i = 1;i <= n;i ++) cout << c[i] << ' ';
        cout << '\n';
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}

/*
4
5 4 0
1 5 4 3 2
5 4 1
1 5 4 3 2
5 4 4
10 20 30 40 50
10 7 3
4 6 8 2 9 9 7 4 10 9
*/

/*
1 2 3 4
5 6 7 8
9

9 2 3 4
5 6 7 8
1

9 1 2 3
4 5 6 7
8
*/