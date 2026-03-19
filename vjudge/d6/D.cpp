#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,k,mi;
    cin >> n >> k;
    vector<ll>ar(n);
    for (ll i=0;i<n;i++){
        cin >> ar[i];
    }
    sort(ar.begin(),ar.end());
    mi = ar[n-1] - ar[0];
    for (ll i=0;i<=k;i++){
        mi = min(mi,ar[i+(n-k)-1]-ar[i]);
    }
    cout << mi << '\n';
}