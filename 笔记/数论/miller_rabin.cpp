LL mul(LL a, LL b, LL m) {
    LL r = a * b - m * LL(1.L / m * a * b);
    return r - m * (r >= m) + m * (r < 0);
}

LL pow(LL a, LL b, LL m) {
    LL res = 1 % m;
    for (;b;b >>= 1, a = mul(a, a, m)) {
        if (b & 1) res = mul(res, a, m);
    }
    return res;
}

bool isprime(LL n) {
    if (n < 2 || n % 6 % 4 != 1) {
        return (n | 1) == 3;
    }
    LL s = __builtin_ctzll(n - 1), d = n >> s;
    for (LL a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        LL p = pow(a % n, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i --) {
            p = mul(p, p, n);
        }
        if (p != n - 1 && i != s) return 0;
    }
    return 1;
}