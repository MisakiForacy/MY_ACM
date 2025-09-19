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

LL gcd(LL a, LL b){
    return (b ? gcd(b, a % b) : a);
}

void fxy_ac(){
    LL n, ans = 0;
    cin >> n;
    map<int, int> mp;
    for (int i = 1;i <= n;i ++){
        for (int j = 1;j <= n;j ++){
            ans += gcd(gcd(i, n), gcd(j, n));
            mp[gcd(gcd(i, n), gcd(j, n))] ++;
            // cout << gcd(i, n) << ' ' << gcd(j, n) << ' ' << gcd(gcd(i, n), gcd(j, n)) << '\n';
        }
    }
    for (auto [k, v] : mp){
        cout << k << ' ' << v << '\n';
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