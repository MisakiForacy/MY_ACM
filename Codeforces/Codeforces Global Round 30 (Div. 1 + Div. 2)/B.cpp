#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

const int N = 2e5;
const LL inf = 1e15;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1), eve, odd;
    for (int i = 1; i <= n;i ++) {
        cin >> a[i];
        if (a[i] & 1) odd.push_back(a[i]);
        else eve.push_back(a[i]);
    }
    if (eve.size() >= 2) {
        cout << eve[0] << ' ' << eve[1] << '\n';
        return;
    }
    if (eve.size() == 1) {
        LL y = eve[0];
        for (LL x : odd) {
            if (x < y && ((y / x) % 2 == 0)) {
                cout << x << ' ' << y << '\n';
                return;
            }
        }
    }
    for (int i = 0; i < siz(odd) - 1;i ++) {
        if (odd[i + 1] < 2 * odd[i]) {
            cout << odd[i] << ' ' << odd[i + 1] << '\n';
            return;
        }
    }
    for (int i = 0; i < siz(odd);i ++) {
        for (int j = i + 1; j < siz(odd);j ++) {
            if (!((odd[j] % odd[i]) & 1)) {
                cout << odd[i] << ' ' << odd[j] << '\n';
                return;
            }
        }
    }
    cout << -1 << '\n';
}

int main () {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}