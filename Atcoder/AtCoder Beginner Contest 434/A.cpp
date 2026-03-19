#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve () {
    LL w, b;
    cin >> w >> b;
    cout << (w * 1000 + b) / b << '\n';
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve ();
}