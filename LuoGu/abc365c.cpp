#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,m;
    cin >> n >> m;
    vector<ll>a(n);
    ll sum = 0;
    for (int i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(),a.end());
    vector<ll>pre(n+1,0);
    for (int i=1;i<=n;i++){
        pre[i] = pre[i-1] + a[i-1];

    }
    if (sum <= m){
        cout << "infinite\n";
    } else{
        ll mx = 0;
        for (int i=n-1;i>=0;i--){
            mx = max(mx,(m-pre[i]+pre[0])/(n-i));
        }
        cout << mx << '\n';
    }
}