#include <bits/stdc++.h>

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve() {
    LL x;
    cin >> x;
    cout << __builtin_popcountll(x ^ 1) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}