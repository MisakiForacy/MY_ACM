#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

const LL N = 1e6 + 5;

vector<int> P, S(N, 0);

void euler() {
    for (int i = 2;i < N;i ++) {
        if (!S[i]) S[i] = i, P.push_back(i);
        for (int j = 0;j < siz(P) && i * P[j] < N;j ++) {
            S[i * P[j]] = P[j];
            if (i % P[j] == 0) break;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    if (is_sorted(a.begin() + 1, a.end())) {
        cout << "Bob\n";
        return;
    }
    for (int i = 1;i <= n;i ++) {
        vector<int> use;
        while (a[i] != 1) {
            use.push_back(S[a[i]]);
            a[i] /= S[a[i]];
        }
        sort(all(use));
        if (siz(use) && use[0] != use.back()) {
            cout << "Alice\n";
            return;
        }
        if (siz(use)) a[i] = use[0];
    }
    if (is_sorted(a.begin() + 1, a.end())) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
    }
}

int main() {
    euler();
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}