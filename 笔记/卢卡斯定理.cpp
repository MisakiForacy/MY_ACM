#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const LL N = 1e5 + 1;
LL fac[N];
LL qmi(LL a,LL k,LL p){
    LL res = 1;
    while (k){
        if (k&1) (res *= a) %= p;
        a = a * a % p;
        k >>= 1;
    }
    return res;
}
LL inv(LL a,LL p){
    LL res = 1;
    LL k = p - 2;
    while (k){
        if (k & 1) (res *= a) %= p;
        (a *= a) %= p;
        k >>= 1;
    }
    return res;
}
LL C(LL m, LL n, LL p){
    if (m > n) return 0;
    return fac[n] * inv(fac[m], p) % p * inv(fac[n - m], p) % p;
}
LL lucas(LL m, LL n, LL p){
    if (m == 0) return 1;
    return lucas(m / p, n / p, p) * C(m % p, n % p, p) % p;
}