#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        ll n,k;
        cin >> n >> k;
        vector <ll> a(n+1),pre(n+1,0),suf(n+2,0);
        for (int i=1;i<=n;i++){
            cin >> a[i];
            pre[i] = a[i] + pre[i-1];
        }
        ll lo = k/2 + (k%2?1:0);
        ll hi = k/2;
        for (int i=1;i<=n;i++){
            if (pre[i]>=lo){
                a[i] = (pre[i]-lo);
                break;
            } else{
                a[i] = 0;
            }
        }
        ll mx = 0;
        for (int i=n;i>=1;i--){
            suf[i] = a[i] + suf[i+1];
            mx = max(mx,suf[i]);
            if (suf[i]>=hi){
                a[i] = (suf[i]-hi);
                break;
            }
            else{
                a[i] = 0;
            }
        }
        ll cnt = n;
        for (int i=1;i<=n;i++){
            // cout << a[i] << " \n"[i==n];
            if (a[i]){
                cnt --;
            }
        }
        cout << cnt << '\n';
    }
}