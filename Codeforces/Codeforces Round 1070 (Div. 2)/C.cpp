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
    vector<LL> a(n + 1);
    vector<LL> o, e;
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
        if (a[i] & 1)
            o.push_back(a[i]);
        else   
            e.push_back(a[i]);
    }
    sort(all(o)), sort(all(e), greater());
    int m = siz(e);

    if (siz(o) == 0) {
        for (int i = 1;i <= n;i ++) cout << 0 << ' ';
        cout << '\n';
        return;
    }

    if (siz(e) == 0) {
        for (int i = 1;i <= n;i ++) {
            if (i & 1) 
                cout << o.back() << ' ';
            else
                cout << 0 << ' ';
        }
        cout << '\n';
        return;
    }


    vector<LL> p(m + 1, 0);
    for (int i = 1;i <= m;i ++) p[i] = p[i - 1] + e[i - 1];

    LL x = o.back();
    o.pop_back();

    int l = 0, r = 0;
    for (int i = 1;i <= n;i ++) {
        if (r <= siz(o))
            cout << x + p[l] << ' ';
        else
            cout << 0 << ' ';
        l ++;
        if (l > m) l -= 2, r += 2;
        // cout << l << ' ' << r << '\n';
    }
    cout << '\n';

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T --) solve();
}