#include <bits/stdc++.h>
using namespace std;
using LL = long long;

mt19937_64 rnd(time(0));

int randint(int l, int r) {
    return l + (rnd() % (r - l + 1));
}

int main () {
    cout << 1 << '\n';
    LL n = randint(10, 1000);
    LL k = randint(1, 1000);
    cout << n << ' ' << k << '\n';
    for (int i = 1;i <= n;i ++) cout << randint(-10000, 10000) << " \n"[i == n];
    for (int i = 1;i <= n;i ++) cout << randint(0, 10000) << " \n"[i == n];
}