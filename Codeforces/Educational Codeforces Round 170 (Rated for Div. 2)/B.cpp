#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL qpow(LL a,LL x,LL mod){
    LL res = 1;
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
    vector<int> n(T);
    vector<int> k(T);
    for (int i=0;i<T;i++) cin >> n[i];
    for (int i=0;i<T;i++) cin >> k[i];
    for (int i=0;i<T;i++){
        cout << qpow(2,k[i],1e9+7) << '\n';
    }
}