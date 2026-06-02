#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

vector<string> v(25 * 25);

void solve() {
    int n, m, k, mxx=0;
    cin >> n >> m >> k;
    if (m >= k) {
        cout << "No\n";
        return;
    }
    if (m == 0) {
        if (n > 26) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
            for (char c = 'a';c < 'a' + n;c ++) {
                for (int j = 0;j < k;j ++) {
                    cout << c;
                }
                cout << '\n';   
            }
        }
        return;
    }
    vector<string> p(n);
    int idx = 0;
    for (int i = 0;i < n;i ++) {
        string u1;
        for (int j = 0;j < m - 1;j ++) u1.push_back('z');
        p[i] += u1;
        while (siz(p[i]) < k) p[i] += v[idx];
        while (siz(p[i]) > k) p[i].pop_back();
        idx ++;
    }
    cout << "Yes\n";
    for (auto s : p) cout << s << '\n';
}

int main() {
    int idx = 0;
    for (char x = 'a';x <= 'y';x ++) {
        for (char y = x;y <= 'y';y ++) {
            v[idx].push_back(x);
            v[idx].push_back(y);
            idx ++;
        }
    }
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}