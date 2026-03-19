#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
ll qpow(ll a,ll k){
    ll res = 1;
    while (k){
        if (k&1) res = res * a % mod;
        a = a * a % mod;
        k >>= 1;
    }
    return res;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        if (n%3==2){
            cout << qpow(2,(n-1)) << '\n';
        } else{
            cout << qpow(2,n) << '\n';
        }
    }
}