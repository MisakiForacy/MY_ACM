#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL MOD = 998244353;

LL qmi(LL a, LL k){
    LL res = 1;
    while (k){
        if (k & 1) (res *= a) %= MOD;
        (a *= a) %= MOD;
        k >>= 1;
    }
    return res;
}

void solve(){
    string n;
    LL k, a = 0;
    cin >> n >> k;
    LL phi = MOD - 1;
    for (char x : n){
        a *= 10;
        a += x - '0';
        a %= phi;
    }
    cout << (qmi(k, a) - qmi(k - 1, a) + MOD) % MOD << '\n';
}

int main(){
    int T = 1;
    // cin >> T;
    while (T --) solve();
}