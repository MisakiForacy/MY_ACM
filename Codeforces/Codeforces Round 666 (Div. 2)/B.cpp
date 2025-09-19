#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
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

LL qmi(LL a,LL k)
{
    long long res = 1;
    while (k){
        if (k&1) res *= a;
        a = a * a;
        k >>= 1;
    }
    return res;
}

void fxy_ac(){
    int n;
    cin >> n;
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;++ i)
    {
        cin >> a[i];
    }
    for (int i = 2;i <= 32;i ++){
LL val = 0;        
        for (int j = 1;j <= n;j ++){
            val += abs(qmi(i, ))
        }
    }
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