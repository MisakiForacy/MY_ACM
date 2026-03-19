#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,k,x;
    cin >> n >> k;
    vector<ll>ar(n+1);
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    sort(ar.begin()+1,ar.end());
    if (k){
        if (ar[k+1]==ar[k]){
            cout << -1 << '\n';
        } else{
            cout << ar[k] << '\n';
        }
    } else{
        if (ar[1]==1){
            cout << -1 << '\n';
        } else{
            cout << 1 << '\n';
        }
    }
}