#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
const i64 mod = 998244353;
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
    int T;
    cin >> T;
    while (T--){
        i64 n;
        cin >> n;
        cout << qpow(2,n,mod)-1 << '\n';
    }
}