using LL = long long;

mt19937_64 rnd(time(0));

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

LL pollard(LL n) {
    if (n % 2 == 0) return 2;
    if (n % 3 == 0) return 3;
    while (1) {
        LL c = rnd() % (n - 1) + 1;
        LL x = rnd() % (n - 1) + 1;
        LL y = x;
        LL d = 1;
        auto f = [&](LL x) {
            return (mul(x, x, n) + c) % n;
        };
        while (d == 1) {
            x = f(x);
            y = f(f(y));
            d = __gcd(abs(x - y), n);
        }
        if (d != n) return d;
    }
}

void factor(LL n, vector<LL>& res) {
    if (n == 1) return;

    if (isprime(n)) {
        res.push_back(n);
        return;
    }
    LL d = pollard(n);
    factor(d, res);
    factor(n / d, res);
}
