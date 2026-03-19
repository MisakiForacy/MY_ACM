#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define sll __int128
#define lld long double

constexpr ll INF = 0x7FFFFFFFFFFFFFFF;
constexpr ll MOD = 998244353;
using namespace std;

template <const ll MOD>
struct ModInt
{
    ll x;
    ModInt(ll n = 0)
    {
        x = n % MOD;
        if (x < 0)
            x += MOD;
    }
    ModInt qmi(ll k) const
    {
        ModInt res = 1, a = *this;
        while (k)
        {
            if (k & 1)
                res *= a;
            a *= a;
            k >>= 1;
        }
        return res;
    }
    ModInt inv() const { return qmi(MOD - 2); }
    ModInt &operator+=(const ModInt &b)
    {
        if ((x += b.x) >= MOD)
            x -= MOD;
        return *this;
    }
    ModInt &operator-=(const ModInt &b)
    {
        if ((x -= b.x) < 0)
            x += MOD;
        return *this;
    }
    ModInt &operator*=(const ModInt &b)
    {
        x = x * b.x % MOD;
        return *this;
    }
    ModInt &operator/=(const ModInt &b) { return *this *= b.inv(); }
    friend ModInt operator+(ModInt a, const ModInt &b) { return a += b; }
    friend ModInt operator-(ModInt a, const ModInt &b) { return a -= b; }
    friend ModInt operator*(ModInt a, const ModInt &b) { return a *= b; }
    friend ModInt operator/(ModInt a, const ModInt &b) { return a /= b; }
    friend bool operator==(const ModInt &a, const ModInt &b) { return a.x == b.x; }
    friend bool operator!=(const ModInt &a, const ModInt &b) { return a.x != b.x; }
    friend bool operator<(const ModInt &a, const ModInt &b) { return a.x < b.x; }
    friend std::ostream &operator<<(std::ostream &out, const ModInt &a) { return out << a.x; }
    friend std::istream &operator>>(std::istream &in, ModInt &a)
    {
        ll t;
        in >> t;
        a = ModInt(t);
        return in;
    }
};

inline ll read()
{
    ll x = 0;
    bool flag = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            flag = 0;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    }
    if (flag)
        return x;
    return ~(x - 1);
}

inline void write(ll x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x >= 10)
        write(x / 10);
    putchar(x % 10 + '0');
}

inline void solve()
{
    // ll n = read(), m = read(), k = read();
    ll n, m, k;
    cin >> n >> m >> k;
    ll w[n + 10], a[n + 10];
    ll maxx = m;
    if ((n - 1) * n / 2 > k)
    {
        cout << "NO" << "\n";
        return;
    }
    for (int i = 2; i <= n; i++)
    {
        w[i] = (ll)(i - 1) * (i - 2) / 2 + 1;
        a[i] = i - 1;
        k -= i - 1;
    }
    for (int i = n; i >= 2; i--)
    {
        if (k == 0)
            break;
        ll maxx = min(m - n + i, w[i]);
        ll x = min(k, maxx - i + 1);
        a[i] += x;
        k -= x;
    }
    if (k > 0)
    {
        cout << "NO" << "\n";
        return;
    }
    ll vis[m + 10] = {0};
    ll cnt = m;
    cout << "YES" << "\n";
    for (int i = 2; i <= n; i++)
    {
        cout << "1 " << i << " " << a[i] << "\n";
        vis[a[i]] = 1;
    }
    ll now = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= i; j++)
        {
            if (i == j)
                continue;
            while (vis[now])
            {
                now++;
            }
            if (now > m)
                break;
            cout << i << " " << j << " " << now << "\n";
            vis[now] = 1;
        }
        if (now > m)
            break;
    }
    return;
}

int main()
{
    ll T = 1;
    // T = read();
    while (T--)
    {
        solve();
    }
    return 0;
}