// By Foracy
/*    Talk Is Cheap, Show Me Your Code    */
#pragma GCC optimize(2) // 开启O2优化
#include <bits/stdc++.h>
#define N (i64)(1e3+10) // 常数
#define EPS 1e-2    // 控制浮点数精度
#define all(x) begin(x),end(x)
#define lcm(x,y) (x) * (y) / __gcd((x),(y)) // 最小公约数
using namespace std;
typedef long long i64;
typedef unsigned long long ull;
typedef long double llf;
const ull mod = 1e9 + 7;    // 取模
const i64 inf = 0x3f3f3f3f3f3f3f;   // 无穷大
const llf PI = acos(-1.0);  // PI
i64 read(){   // 整型快速读入
    int _s = 0, _w = 1;
    char _ch = getchar();
    while(_ch<'0'||_ch>'9'){if(_ch=='-')_w=-1;_ch=getchar();}
    while('0'<=_ch&&_ch<='9'){_s = _s*10+_ch-'0';_ch=getchar();}
    return _s*_w;
}
void readline(string &_str,char _end = '\n'){ // 字符串快速读入
    _str.clear();
    char _ch = getchar();
    while(!(_ch==_end||_ch=='\n')){_str.push_back(_ch);_ch=getchar();}
}
void write(int _x){   // 快速打印
    if (_x < 0){putchar('-');_x=-_x;}
    if (_x > 9){write(_x / 10);}
    putchar(_x % 10 + '0');
}
llf fgcd(llf _a,llf _b){    // 浮点数求公约数
    if (fabs(_b) < EPS) return _a;
    if (fabs(_a) < EPS) return _b;
    return fgcd(_b,fmod(_a,_b));
}
i64 n,m,k,r,l;
i64 num,cnt,res,sum,ave,tot,ans,val,len,ma,mi;
bool flg;
string s,str;
void solve(){
    // Code
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = read();
    while(T --){
        solve();
    }
    return 0;
}