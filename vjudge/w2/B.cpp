#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,k,a,b;
    cin >> n >> k;
    ll tt = 0,t = 0,bb = 0;
    for (ll i=0;i<n;i++){
        cin >> a >> b;
        tt += a + k*b;
        t += tt;
        bb += b;
    }
    t += bb*20;
    cout << t << '\n';
}