#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define debug(x) cerr << #x << ':' << x << ' ';
#define nl cerr << '\n';
using namespace std;
const int N = 1e5 + 10; // 需调整
using LL = long long;
const LL inf = LLONG_MAX;
const LL MOD7 = 1e9 + 7;
const LL MOD3 = 998244353;

void fxy_ac(){
    LL n, ans = 0;
    cin >> n;
    for (int i = 1;i <= n;){
        LL lo = 0, hi = n;
        LL p = n / i;
        auto check = [&](LL x) -> bool {
            return (n / (i + x) == n / i);
        };
        while (lo < hi){
            LL mid = (lo + hi) / 2;
            if (check(mid)) lo = mid + 1;
            else hi = mid - 1;
        }
        if (!check(lo)) lo --;
        lo ++;
        // cout << i << ' ' << p << ' ' << lo << '\n';
        ans += (n % i + n % i - (lo - 1) * p) * lo / 2;
        i += lo;
    }
    cout << ans << '\n';
}

void brute(){ // 暴力

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T; // 需调整
    while (T --){
        fxy_ac();
        // brute();
    }
}