#include <bits/stdc++.h>

#define x first 
#define y second 

#define LOG 30

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

struct node
{
    LL a, h, id;
    bool operator < (const node&T) const {
        return a < T.a;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<node> p(n);
    for (int i = 0;i < n;i ++) 
        cin >> p[i].a, p[i].h = p[i].a, p[i].id = i + 1;
    sort(all(p));
    vector<PLL> Ans;
    if (m > n / 2) {
        cout << -1 << '\n';
    } else if (m != 0) {
        int l = n - 2 * m, r = n - m + 1;
        cout << n - m << '\n';
        for (int i = 1;i <= l;i ++) {
            cout << p[i - 1].id << ' ' << p[i].id << '\n';
        }
        for (int i = r;i <= n;i ++) {
            cout << p[i - 1].id << ' ' << p[i - m - 1].id << '\n';
        }
    } else if (m == 0) {
        LL Sm = 0, ok = 0, l;
        for (int i = n - 2;i >= 0;i --) {
            Sm += p[i].a;
            if (Sm >= p[n - 1].h) {
                l = i;
                ok = 1;
                break;
            }
        }
        if (!ok) {
            cout << -1 << '\n';
        } else {
            cout << n - 1 << '\n';
            for (int i = 0;i < l;i ++) {
                cout << p[i].id << ' ' << p[i + 1].id << '\n';
            }
            for (int i = l;i < n - 1;i ++) {
                cout << p[i].id << ' ' << p[n - 1].id << '\n';
            }
        }
    }
}

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}