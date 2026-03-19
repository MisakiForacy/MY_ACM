#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

const int N = 1e5 + 5;

vector<int> P, S(N, 0);

void Euler() {
    for (int i = 2;i < N;i ++) {
        if (!S[i]) P.push_back(i);
        for (int j = 0;j < siz(P) && P[j] * i < N;j ++) {
            S[P[j] * i] = 1;
            if (i % P[j] == 0) break;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<LL> a(n), b(m);
    LL Sa = 0, Sb = 0;
    for (int i = 0;i < n;i ++) cin >> a[i], Sa += a[i];
    for (int i = 0;i < m;i ++) cin >> b[i], Sb += b[i];
    sort(all(a), greater());
    sort(all(b), greater());
    if (Sa == Sb) {
        cout << 1 << '\n';
    } else if (Sa > Sb) {
        LL S = 0;
        for (int i = 0;i < n;i ++) {
            S += a[i];
            if (Sa - S <= Sb) {
                cout << i + 1 << '\n';
                return;
            }
        }
    } else {
        LL S = 0;
        for (int i = 0;i < m;i ++) {
            S += b[i];
            if (Sb - S <= Sa) {
                cout << i + 1 << '\n';
                return;
            }
        }
    }
}

int main() {
    Euler();
    // cout << siz(P) << '\n';
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}