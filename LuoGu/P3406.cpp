#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,m;
    cin >> n >> m;
    vector<ll>ti(n+2,0);
    ll la,no;
    cin >> la;
    for (int i=1;i<m;i++){
        cin >> no;
        ti[min(la,no)] ++;
        ti[max(la,no)] --;
        la = no;
    }
    for (int i=1;i<=n;i++){
        ti[i] = ti[i] + ti[i-1];
        // cout << ti[i] << " \n"[i==n];
    }
    ll a,b,c,ans = 0;
    for (int i=1;i<n;i++){
        cin >> a >> b >> c;
        ans += min(c+ti[i]*b,ti[i]*a);
    }
    cout << ans << '\n';
}