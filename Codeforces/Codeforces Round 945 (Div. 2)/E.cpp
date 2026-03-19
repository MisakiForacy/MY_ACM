// By Foracy
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
#define N (i64)(1e3+10)
#define all(x) begin(x),end(x)
using namespace std;
typedef long long i64;
typedef unsigned long long ull;
typedef double llf;
const ull mod = 1e9 + 7;
const i64 inf = 0x3f3f3f3f3f3f3f;
static inline int read(){
    int _s = 0, _w = 1;
    char _ch = getchar();
    while(_ch<'0'||_ch>'9'){if(_ch=='-')_w = -1; _ch = getchar();}
    while('0'<=_ch&&_ch<='9'){_s = _s*10+_ch-'0';_ch = getchar();}
    return _s * _w;
}
static inline void write(int _x){
    if (_x < 0){putchar('-');_x = -_x;}
    if (_x > 9){write(_x / 10);}
    putchar(_x % 10 + '0');
}
i64 t,n,m,k,r,l;
i64 num,cnt,res,sum,ave,tot,ans,Max,Min;
bool flg,flg1,flg2;
string s,s1,s2,str,str1,str2;
void solve(){
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    t = read();
    while(t --){
        solve();
    }
    return 0;
}