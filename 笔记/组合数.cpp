#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 1e5 + 10;
const LL MOD = 1e9 + 7;

LL A[N];

LL inv(LL a){
    LL k = MOD - 2;
    LL res = 1;
    while (k){
        if (k & 1) res = res % MOD * a % MOD;
        a = a % MOD * a % MOD;
        k >>= 1;
    }
    return res;
}

LL cal(LL n, LL m){ // 从n里面选m个
    if (n < m) return 0; 
    if (n == 0 || n == m) return 1;
    return A[n] * inv(A[n - m]) % MOD * inv(A[m]) % MOD;
}

int main(){
    A[0] = 1;
    for (int i = 1;i < N;i ++){
        A[i] = A[i - 1] % MOD * i % MOD;
    }
    cout << cal(4, 2) << '\n';
}