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

void fxy_ac(){
    LL a, b, c;
    cin >> a >> b >> c;
    cout << a * 79 + b * 89 + c * 100 << ' ' << a * 60 + b * 80 + c * 90 << '\n';
}

void brute(){ // 暴力

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T; // 多测
    while (T --){
        fxy_ac();
        // brute();
    }
}