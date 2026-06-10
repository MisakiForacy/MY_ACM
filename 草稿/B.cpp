#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

const int N = 1e6 + 10;

vector<LL> S(N, 0), P, use(1010, 0);

void init() {
    S[1] = S[0] = 1;
    for (int i = 2;i < N;i ++) {
        if (!S[i]) P.push_back(i);
        for (int j = 0;j < siz(P) && P[j] * i < N;j ++) {
            S[P[j] * i] = 1;
            if (i % P[j] == 0) break;
        }
    }
    for (int i = 1;i * i <= 100;i ++) use[i * i] = 1; 
}

int main() {
    init();
    ios::sync_with_stdio(0), cin.tie(0);
    LL l, r, k, cnt = 0;
    cin >> l >> r >> k;
    // l = 1e12 - 1e6, r = 1e12, k = 100000000;
    // assert (r <= 1e12);
    // cout << l << ' ' << r << '\n';
    for (LL val = l;val <= r;val ++) {
        // cout << val << ' ';
        LL Tp = val, sum = 0;
        while (Tp) {
            sum += Tp % 10;
            Tp /= 10;
        }
        // cout << sum << '\n';
        if (use[sum]) cnt ++;
        if (use[sum] && val != 1) {
            int f = 0;
            for (auto v : P) {
                if (v * v > val) break;
                if (val % v == 0) {
                    f = 1;
                    break;
                }
            }
            if (f) continue;
            k --;
        }
        if (!k) {
            cout << cnt << '\n';
            // cout << val << '\n';
            return 0;
        }
    }
    cout << cnt << '\n';
    // cout << -1 << '\n';
}