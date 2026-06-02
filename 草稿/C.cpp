#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const LL mod = 998244353;

LL qmi(LL a, LL k) {
    LL res = 1;
    while (k) {
        if (k & 1) 
            res *= a, res %= mod;
        a = a * a % mod;
        k >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    LL k;
    cin >> s >> k;
    LL t = 0;
    for (char c : s) {
        t *= 10;
        t += c - '0';
        t %= mod - 1;
    }
    LL t1 = qmi(k, t);
    LL t2 = qmi(k - 1, t);
    cout << (t1 - t2 + mod) % mod << '\n';
}