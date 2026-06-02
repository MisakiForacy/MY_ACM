#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n;
    char c;
    cin >> n;
    string ca, cb;
    cin >> ca >> cb;
    ca = ' ' + ca;
    cb = ' ' + cb;
    vector<int> a(n + 2, 0), b(n + 2, 0);
    for (int i = 1;i <= n;i ++) {
        a[i] = a[i - 1] + (ca[i] == '(' ? 1 : -1);
    }
    for (int i = 1;i <= n;i ++) {
        b[i] = b[i - 1] + (cb[i] == '(' ? 1 : -1);
    }
    int ok = 1;
    int offa = 0, offb = 0;
    for (int i = 1;i <= n;i ++) {
        if (a[i] + offa < 0 || b[i] + offb < 0) {
            if (a[i] + offa < 0 && b[i] + offb > 0) {
                offa += 2;
                offb -= 2;
            } else if (a[i] + offa > 0 && b[i] + offb < 0) {
                offa -= 2;
                offb += 2;
            }
            if (a[i] + offa < 0 || b[i] + offb < 0) ok = 0;
        }
    }
    if (a[n] + offa != 0 || b[n] + offb != 0) ok = 0;
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}
