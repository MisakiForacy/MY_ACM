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
    int n, m;
    cin >> n >> m;
    vector<LL> a(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    sort(all(a));
    LL lo = 1, hi = a[n] * a[n - 1];
    auto check = [&](LL x) -> bool {
        int l = 1, r = n, cnt = 0;
        while (l < r){
            if (a[l] * a[r] >= x){
                l ++, r --;
                cnt ++;
            } else{
                l ++;
            }
        }
        // cout << x << ' ' << cnt << ' ' << m << '\n';
        return cnt >= m;
    };  
    while (lo < hi){
        LL mid = (lo + hi) / 2;
        if (check(mid)) lo = mid + 1;
        else hi = mid - 1;
    }
    if (!check(lo)) lo --;
    cout << lo << '\n';
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