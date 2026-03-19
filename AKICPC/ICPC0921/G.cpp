#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll qpower(ll a,ll k,ll p){
    ll res = 1;
    while (k){
        if (k&1) res = a * res % p;
        a = a * a % p;
        k >>= 1;
    }
    return res;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        ll x,y,a0,a1,b;
        cin >> x >> y >> a0 >> a1 >> b;
        
    }
}