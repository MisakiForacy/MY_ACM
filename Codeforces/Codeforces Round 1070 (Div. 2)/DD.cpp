#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL f[100];

int main() {
    f[1] = 1;
    for (int i = 2;i <= 88;i ++) {
        f[i] = f[i - 1] + f[i - 2];
        cout << f[i] << '\n';
    }
}