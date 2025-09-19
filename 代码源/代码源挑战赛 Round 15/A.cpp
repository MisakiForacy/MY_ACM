#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve(){
    int x, y, t;
    cin >> x >> y >> t;
    x += t / 60;
    y += t % 60;
    x += y / 60;
    y %= 60;
    cout << x % 24 << ' ' << y << '\n';
}

int main(){
    int T = 1;
    // cin >> T;
    while (T --) solve();
}