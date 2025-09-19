#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL qpow(LL a,LL x,LL mod){
    LL res = 1;
    while (x){
        if (x&1) res = res % mod * a % mod;
        a = a % mod * a % mod;
        x >>= 1;
    }
    return res;
}
int main(){
    LL a,x,mod;
    cin >> a >> x >> mod;
    cout << qpow(a,x,mod) << '\n';
}