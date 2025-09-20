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
    LL a, b, r;
    cin >> a >> b >> r;
    if (a < b) swap(a, b);
    LL x = 0;
    for (int i = 62;i >= 0;i --){
        if ((a & (1LL << i)) > (b & (1LL << i)) && (x + (1LL << i) <= r)){
            x += (1LL << i);
            if ((b ^ x) > (a ^ x)){
                x -= (1LL << i);
            }
        }
    }
    cout << abs((a ^ x) - (b ^ x)) << '\n';
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