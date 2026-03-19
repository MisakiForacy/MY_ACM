#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
i64 qpow(i64 a,i64 x,i64 mod){
    i64 res = 1;
    while (x){
        if (x&1) res = res * a % mod;
        a = a * a % mod;
        x >>= 1;
    }
    return res;
}
int main(){
    i64 a,x,mod;
    cin >> a >> x >> mod;
    printf("%ld^%ld mod %ld=%ld",a,x,mod,qpow(a,x,mod));
    // cout <<  << '\n';
}