#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

const LL N = 2e7 + 5;
const LL MOD = 104206969;

vector<LL> P = {0}, P1 = {0}, P2 = {0}, S(N, 0), p1 = {0}, p2 = {0}, p3 = {0};

void pri() {
    S[0] = S[1] = 1;
    for (int i = 2;i < N;i ++) {
        if (!S[i]) P.push_back(i);
        for (int j = 1;j < siz(P) && P[j] * i < N;j ++) {
            S[P[j] * i] = 1;
            if (i % P[j] == 0) break;
        }
    }
}

void init() {
    LL s = 0;
    for (int i = 1;i < siz(P);i ++) {
        s += P[i];
        s %= MOD;
        p1.push_back(s);
    }
    s = 0;
    for (int i = 1;i < siz(P);i ++) {
        if (!S[P[i] - 2]) {
            P1.push_back(P[i]);
            s += P[i];
            s %= MOD;
            p2.push_back(s);
        }
    }
    s = 0;
    for (int i = 1;i < siz(P);i ++) {
        if (P[i] > 4 && !S[P[i] - 4] && !S[P[i] - 2] && P[i] - 4 != 2) {
            P2.push_back(P[i]);
            s += P[i];
            s %= MOD;
            p3.push_back(s);
        }
    }
}

void solve() {
    LL n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << n << '\n';
    } else if (k == 2) {
        int id = upper_bound(all(P), n) - P.begin() - 1;
        cout << (id * n % MOD - p1[id] + MOD) % MOD << '\n';
    } else if (k == 3) {
        int id = upper_bound(all(P1), n) - P1.begin() - 1;
        cout << (id * n % MOD - p2[id] + MOD) % MOD * 2 % MOD << '\n';
    } else if (k == 4) {
        int id = upper_bound(all(P2), n) - P2.begin() - 1;
        cout << (id * n % MOD - p3[id] + MOD) % MOD << '\n';
    } else {
        cout << 0 << '\n';
    }
}

int main() {
    pri();
    init();
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}