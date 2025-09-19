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
    int n;
    cin >> n;
    vector<LL> a(n, 0), used(n + 1, 0);
    for (int i = 1;i <= n - 1;i ++){
        cin >> a[i];
    }
    map<LL, int> mp;
    LL use = 0, ok = 1;
    for (int i = n - 1;i >= 1;i --){
        if (a[i] - a[i - 1] <= n){
            if (used[a[i] - a[i - 1]]){
                if (use) ok = 0;
                use = a[i] - a[i - 1];
            }
            used[a[i] - a[i - 1]] = 1;
        } else{
            if (use) ok = 0;
            use = a[i] - a[i - 1];
        }
    }
    int cnt = 0;
    // cout << use << ' ' << ok << '\n';
    for (int i = 1;i <= n;i ++){
        if (!used[i]){
            if (use >= i) use -= i;
            else ok = 0;
            cnt ++;
        }
    }
    if (cnt == 1) ok = 1;
    if (use) ok = 0;
    cout << (ok ? "YES\n" : "NO\n");
}

void brute(){ // 暴力

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