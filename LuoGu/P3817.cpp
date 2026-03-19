#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,x,cnt=0;
    cin >> n >> x;
    vector<ll>a(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    for (int i=1;i<n;i++){
        if (a[i]+a[i-1]>x){
            if (a[i]+a[i-1]-x<=a[i]){
                cnt += (a[i]+a[i-1]-x);
                a[i] -= (a[i]+a[i-1]-x);
            } else{
                cnt += (a[i]+a[i-1]-x);
                a[i] = 0;
                a[i-1] = x;
            }
        }
    }
    cout << cnt << '\n';
}