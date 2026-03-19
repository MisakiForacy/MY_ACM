#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve () {
    int n;
    cin >> n;
    vector <LL> a(n + 1), b(n + 1);
    vector <LL> L(n + 1, 0), R(n + 1, 0);
    vector <LL> b1, b2;
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n;i ++) {
        if (L[a[i]]) R[a[i]] = i;
        else L[a[i]] = i;
    }
    for (int i = 1;i <= n;i ++) {
        if (!R[i] && L[i]) {
            b1.push_back (i);
        } else if (!L[i]) {
            b2.push_back (i);
        }
    }
    int use = 0;
    cout << (R[a[1]] ? 1 : 0) << '\n';
    for (int i = 1;i <= n;i ++) {
        if (R[a[i]]) use = 0;
        b[i] = 
    }
}

int main () {
    int T = 1;
    cin >> T;
    while (T --) solve ();
}