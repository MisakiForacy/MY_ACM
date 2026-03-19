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
    LL n, q;
    cin >> n >> q;
    LL use = n, k = 1;
    vector<LL> dep(64, 0);
    for (int i = 1;i <= 60;i ++) {
        if (use >= k) {
            dep[i] = k;
            use -= k;
        } else {
            dep[i] = use;
            break;
        }
        k *= 2;
    }
    while (q --) {
        LL x;
        cin >> x;
        LL v = x;
        for (int i = 1;i <= n;i ++) {
            v -= dep[i];
            if (v <= 0) {
                cout << dep[i] << '\n';
                break;
            }
        }
    }
}

int main() {
    // Euler();
    // cout << siz(P) << '\n';
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}