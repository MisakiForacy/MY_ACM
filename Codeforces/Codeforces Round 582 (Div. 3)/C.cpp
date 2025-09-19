#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define debug(x) cerr << #x << ':' << x << ' ';
#define nl cerr << '\n';
using namespace std;
const int N = 1e5 + 10; // 需调整
using LL = long long;
const LL inf = LLONG_MAX;
const LL MOD7 = 1e9 + 7;
const LL MOD3 = 998244353;

void fxy_ac(){
    LL n, m;
    cin >> n >> m;
    int k = 1;
    LL x = m;
    vector<LL> a = {0};
    a.push_back(m % 10);
    while (x % 10){
        x += m;
        k ++;
        a.push_back(x % 10);
    }
    LL sum = 0;
    for (int i = 1;i < k;i ++) sum += a[i];
    // cout << sum << '\n';
    sum *= n / x;
    // cout << n / x << ' ' << sum << '\n';
    for (int i = 1;i <= n % x / m;i ++){
        sum += a[i];
    }
    cout << sum << '\n';
}

void brute(){ // 暴力
    LL n, m;
    LL sum = 0;
    cin >> n >> m;
    map<int, int> mp;
    for (int i = 0;i <= n;i += m){
        sum += i % 10;
        mp[i % 10] ++;
    }
    for (auto [k, v] : mp){
        cout << k << ':' << v << '\n';
    }
    cout << sum << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T; // 需调整
    while (T --){
        fxy_ac();
        // brute();
    }
}