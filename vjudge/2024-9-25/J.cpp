#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    while (cin >> n){
        ll ans = n * (11 + n) / 2 + 7;
        cout << ans << '\n';
    }
}