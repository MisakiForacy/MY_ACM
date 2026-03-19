#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,cnt = 0;
    cin >> n;
    vector<ll>a(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    a.insert(a.begin(),0);
    for (int i=1;i<=n;i++){
        if (a[i] > a[i-1]){
            cnt += a[i] - a[i-1];
        }
    }
    cout << cnt << '\n';
}