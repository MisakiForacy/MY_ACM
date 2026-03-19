#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll mod = 998244353;
int main(){
    ll n,m,cnt = 0;
    cin >> n >> m;
    ll k = 0;
    while (m){
        k ++;
        if (m&1){
            ll nu = (1LL<<(k-1))*((n+1)/(1LL<<k))%mod;
            if ((n+1)%(1LL<<k)>(1LL<<(k-1))){
                (nu += ((n+1)%(1LL<<k)-(1LL<<(k-1))))%mod;
            }
            (cnt += nu)%mod;
        }
        m >>= 1;
    }
    cout << cnt%mod << '\n';
}