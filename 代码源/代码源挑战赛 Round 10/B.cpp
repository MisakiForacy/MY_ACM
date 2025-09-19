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
    LL n;
    cin >> n;
    LL lo = 1, hi = 1e9;
    auto check = [&](LL x) -> bool {
        return x * x <= n;  
    };
    while (lo < hi){
        LL mid = lo + hi >> 1;
        if (check(mid)) lo = mid + 1;
        else hi = mid - 1;
    }
    if (!check(lo)) lo --;
    cout << lo * lo << '\n';
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