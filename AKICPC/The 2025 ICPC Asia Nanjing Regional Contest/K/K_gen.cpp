#include <bits/stdc++.h>
using namespace std;
using LL = long long;

mt19937_64 rnd(time(0));

LL rd(int l,int r){
    return (rnd() % (r - l + 1) + l);
}

void solve () {
    int x1, y1, x2, y2;
    x1 = rd(1, 9), y1 = rd(1, 10);
    x2 = rd(1, 9), y2 = rd(1, 10);
    cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
}

int main () {
    int T = 1;
    T = 10;
    while (T --) solve ();
}