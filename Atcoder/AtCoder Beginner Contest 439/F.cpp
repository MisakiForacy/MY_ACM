#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL N = 3e5 + 1;

template <const LL MOD>
struct ModInt
{
    LL x;
    ModInt(LL n = 0) { x = (n % MOD + MOD) % MOD; }
    ModInt<MOD> qmi(LL k)
    {
        ModInt<MOD> res = 1;
        ModInt a = *this;
        while (k)
        {
            if (k & 1)
                (res.x *= a.x) %= MOD;
            (a.x *= a.x) %= MOD;
            k /= 2;
        }
        return res;
    }
    ModInt<MOD> inv()
    {
        ModInt<MOD> a = *this;
        return a.qmi(MOD - 2);
    }
    ModInt<MOD> friend operator+(ModInt<MOD> a, ModInt<MOD> b) { return (a.x + b.x) % MOD; }
    ModInt<MOD> friend operator-(ModInt<MOD> a, ModInt<MOD> b) { return (a.x - b.x + MOD) % MOD; }
    ModInt<MOD> friend operator*(ModInt<MOD> a, ModInt<MOD> b) { return a.x % MOD * b.x % MOD; }
    ModInt<MOD> friend operator/(ModInt<MOD> a, ModInt<MOD> b) { return a * b.inv(); }
    ModInt<MOD> friend operator<=(ModInt<MOD> a, ModInt<MOD> b) { return a.x <= b.x; }
    ModInt<MOD> friend operator<(ModInt<MOD> a, ModInt<MOD> b) { return a.x < b.x; }
    ModInt<MOD> friend operator>=(ModInt<MOD> a, ModInt<MOD> b) { return a.x >= b.x; }
    ModInt<MOD> friend operator>(ModInt<MOD> a, ModInt<MOD> b) { return a.x > b.x; }
    ModInt<MOD> friend operator==(ModInt<MOD> a, ModInt<MOD> b) { return a.x == b.x; }
    ModInt<MOD> friend operator!=(ModInt<MOD> a, ModInt<MOD> b) { return a.x != b.x; }
    friend ostream &operator<<(ostream &out, ModInt<MOD> &a) { return out << a.x; }
    friend istream &operator>>(istream &in, ModInt<MOD> &a) { return in >> a.x; }
    ModInt<MOD> operator+=(const ModInt<MOD> &a) { return *this = x + a; }
    ModInt<MOD> operator-=(const ModInt<MOD> &a) { return *this = x - a; }
    ModInt<MOD> operator*=(const ModInt<MOD> &a) { return *this = x * a; }
    ModInt<MOD> operator/=(const ModInt<MOD> &a) { return *this = x / a; }
};

using Z = ModInt<MOD>;

vector<Z> fac(N), invfac(N);

void init()
{
    fac[0] = 1;
    for (int i = 1; i <= N; i++)
        fac[i] = fac[i - 1] * Z(i);
    invfac[N - 1] = Z(1) / fac[N - 1];
    for (int i = N - 2; i >= 0; i--)
        invfac[i] = invfac[i + 1] * Z(i + 1);
}

Z C(LL n, LL m)
{
    Z ret = fac[n] * invfac[m] * invfac[n - m];
    return ret;
}

void solve()
{
    int n;
    cin >> n;
    vector<LL> p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
    {
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
}