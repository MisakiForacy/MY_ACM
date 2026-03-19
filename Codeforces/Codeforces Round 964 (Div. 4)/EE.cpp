#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll qpow(ll a,ll k){
    ll res = 1;
    while (k){
        if (k&1) res = res * a;
        a = a * a;
        k >>= 1;
    }
    return res;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        int lo,hi,ans = 0;
        cin >> lo >> hi;
        for (int i=lo;i<=hi;i++){
            int add = 0;
            while (qpow(3,add)<=i) add ++;
            if (i==lo){
                ans += 2 * add;
            } else{
                ans += add;
            }
        }
        cout << ans << '\n';
    }
}