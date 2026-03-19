#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    ll x = 1;
    while (x<=n) x *= 2;
    if (x-1==n) cout << x-1 << '\n';
    else cout << x/2 - 1 << '\n';
}