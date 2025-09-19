#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define x first
#define y second
#define debug(x) cerr << #x << ':' << x << ' ';
#define nl cerr << '\n';
using namespace std;
const int N = 1e5 + 10; // 需调整
using LL = long long;
const LL inf = LLONG_MAX;
const LL MOD7 = 1e9 + 7;
const LL MOD3 = 998244353;

__int128_t read() {
    __int128_t x = 0;
    bool f = 0;
    char c = getchar();
    while (c < '0' || c > '9') {
    if (c == '-') f = 1;
    c = getchar();
    }
    while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
    }
    return f ? -x : x;
}

void write(__int128_t x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

void fxy_ac(){
    __int128_t n, k;
    n = read(), k = read();
    __int128_t lo = 0, hi = 1e12;
    auto check = [&](__int128_t x) -> bool {
        return x * (x + 1) / 2 * k <= n;
    };
    while (lo < hi){
        __int128_t mid = (lo + hi) / 2;
        if (check(mid)) lo = mid + 1;
        else hi = mid - 1;
    }
    if (!check(hi)) hi -= 1;
    __int128_t s = (n - hi * (hi + 1) / 2 * k) * (hi + 1);
    write(hi + 1); cout << ' '; write(s);
}

void brute(){ // 暴力

}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T; // 多测
    while (T --){
        fxy_ac();
        // brute();
    }
}