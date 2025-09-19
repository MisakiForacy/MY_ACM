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
    int n, cnt = 0;
    cin >> n;
    vector<LL> a(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n - 2;i ++){
        if (a[i] > a[i + 1] && a[i + 1] > a[i + 2]){
            cnt ++;
        }
    }
    cout << cnt << '\n';
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