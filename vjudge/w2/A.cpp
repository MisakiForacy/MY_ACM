#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    for (ll x=1;x<=sqrt(n+1);x++){
        if (!((n+1)%(x+1))&&(n+1)/(x+1)!=1){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}