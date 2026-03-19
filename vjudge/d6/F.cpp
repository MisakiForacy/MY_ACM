#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isprime(ll n){
    for (ll i=2;i<=sqrt(n);i++){
        if (!(n%i)) return 0;
    }
    return 1;
}
int main(){
    int n;
    cin >> n;
    for (ll i=2;i<1e9;i++){
        if ((!isprime(i))&&(!isprime(i+n))){
            cout << i+n << ' ' << i << '\n';
            break;
        }
    }
}