#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    LL a,b,l,r;
    cin >> a >> b >> l >> r;
    LL lcm = a * b / __gcd(a,b);
    LL s, f;
    if (l % lcm == 0){
        s = l;
    } else{
        s = (l / lcm + 1) * lcm;
    }
    f = r / lcm * lcm;
    LL ans;
    if (s <= f){
        ans = (f - s) / lcm + 1;
    } else{
        ans = 0;
    }
    cout << ans << '\n';
}
