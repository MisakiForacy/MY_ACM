#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll T;
    cin >> T;
    while (T--){
        ll n,x;
        cin >> x >> n;
        cout << x - (n-1)/2 << '\n';
    }
}