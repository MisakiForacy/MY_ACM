#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        ll n,m;
        cin >> n >> m;
        vector<ll> a(n+2,0);
        ll mx = 0;
        for (int i=1;i<=n;i++){
            cin >> a[i];
            mx = max(mx,a[i]);
        }
        for (int i=1;i<=m;i++){
            char o; ll l,r;
            cin >> o >> l >> r;
            if (o=='+'){
                if (r >= mx && l<=mx){
                    mx ++;
                }
            } else{
                if (r >= mx && l<=mx){
                    mx --;
                }
            }
            cout << mx << " \n"[i==m];
        }
    }
}