#include <bits/stdc++.h>
using namespace std;
using LL = long long;

mt19937_64 rnd(time(0));

int rd(int l, int r) {
    return l + rnd() % (r - l + 1);
}

int main() {
    int n = rd(1, 200);
    int m = rd(n - 1, min(int(200), n * (n - 1) / 2));
    int k = rd(1, 1000);
    cout << n << ' ' << m << ' ' << k << '\n';
}