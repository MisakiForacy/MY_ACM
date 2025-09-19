#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL gcd(LL a, LL b){
    return (b ? gcd(b, a % b) : a);
}
LL exgcd(LL a, LL b, LL &x, LL &y){
    if (!b){
        x = 1, y = 0;
        return a;
    }
    LL d = exgcd(b, a % b, y, x); // 辗转相除，并交换系数
    /*
    裴属定理：ax + by = gcd(a, b)
    拓欧
        by + (a % b)x = gcd(b, a % b)
      = by + (a - ⌊a / b⌋ * b)x
      = by + ax - ⌊a / b⌋ * b * x
      = ax + b * (y - ⌊a / b⌋ * x)
    */
    y -= a / b * x;
    return d;
}
int main(){
    int T;
    cin >> T;
    while (T --){
        LL a, b, x, y;
        cin >> a >> b;
        exgcd(a, b, x, y);
        cout << x << ' ' << y << '\n';
    }
}