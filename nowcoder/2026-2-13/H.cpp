#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    const int MAXV = 2048; // values always in [0,2047]
    vector<char> cur(MAXV, 0), nxt(MAXV, 0);
    cur[0] = 1;

    for (int i = 0; i < n; ++i) {
        fill(nxt.begin(), nxt.end(), 0);
        for (int v = 0; v < MAXV; ++v) if (cur[v]) {
            int v1 = v - a[i];
            if (v1 < 0) v1 = 0;
            nxt[v1] = 1;
            nxt[v ^ b[i]] = 1;
        }
        cur.swap(nxt);
    }

    for (int v = MAXV - 1; v >= 0; --v) if (cur[v]) {
        cout << v << '\n';
        return 0;
    }
    cout << 0 << '\n';
    return 0;
}