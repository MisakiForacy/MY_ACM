#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

struct node
{
    LL x, id;
    bool operator < (const node&T) const {
        return x < T.x;
    }
};


void solve() {
    int n;
    cin >> n;
    vector<node> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i].x, a[i].id = i;
    sort(a.begin() + 1, a.end());
    map<LL, int> mp;
    for (int i = 2;i <= n;i ++) {
        mp[a[i].x - a[i - 1].x] ++;
    }
    if (siz(mp) > 10) {
        cout << -1 << '\n';
        return;
    }
    for (auto [k, v] : mp) {
        int ok = 1;
        for (int i = 2;i <= n;i ++) {
            if (a[2].x + k * (i - 2) != a[i].x) ok = 0;
        }
        if (ok) {
            cout << a[1].id << '\n';
            return;
        }
        vector<int> b;
        for (int i = 1;i <= n;i ++) {
            if (a[1].x + k * (i - (siz(b) + 1)) != a[i].x) {
                b.push_back(a[i].id);
            }
        }
        if (siz(b) == 1) {
            cout << b[0] << '\n';
            return;
        } else if (siz(b) == 0) {
            cout << a[1].id << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve(); 
}