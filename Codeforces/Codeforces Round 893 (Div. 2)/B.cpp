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
    LL n, m, d;
    LL tot, cnt, Max;
    tot = cnt = Max = 0;
    cin >> n >> m >> d;
    vector<LL> a(m + 2), b(m + 1), c(m + 1);
    a[0] = 1, a[m + 1] = n + 1;
    for (int i = 1;i <= m;i ++){
        cin >> a[i];
    }
    for (int i = 1;i <= m + 1;i ++){
        if (a[i] != a[i - 1]){
            tot += (a[i] - a[i - 1] - 1) / d + 1;
        }
    }
    for (int i = 1;i <= m;i ++){
        if (a[i] != a[i - 1]){
            b[i] = (a[i] - a[i - 1] - 1) / d + (a[i + 1] - a[i] - 1) / d + 2;
        } else{
            b[i] = (a[i + 1] - a[i] - 1) / d + 1;
        }
        c[i] = (a[i + 1] - a[i - 1] - 1) / d + 1;
        Max = max(Max, b[i] - c[i]);
    }
    for (int i = 1;i <= m;i ++){
        if (b[i] - c[i] == Max) cnt ++;
    }
    tot -= Max;
    cout << tot << ' ' << cnt << '\n';
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