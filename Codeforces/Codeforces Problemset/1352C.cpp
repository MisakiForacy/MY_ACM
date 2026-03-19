#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    ll n,k;
    cin >> T;
    while (T--){
        cin >> n >> k;
        if (k < n){
            cout << k << '\n';
        } else {
            ll t = k/n;
            ll tt = (k+t)/n;
            while (t!=tt){
                t = (k+tt)/n;
                tt = (k+t)/n;
            }
            cout << k+t << '\n';
        }
    }
}