#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll qpower(ll a,ll k){
    ll res = 1;
    while (k){
        if (k&1) res = res * a;
        a = a*a;
        k >>= 1;
    }
    return res;
}
ll BtoD(string s){
    ll ans = 0;
    int len = s.length();
    for (int i=0;i<len;i++){
        ans += (s[i]=='1') * qpower(2,len-i-1);
    }
    return ans;
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> a(n+1,0);
    vector<vector<ll>> pre(31,vector<ll>(n+1,0));
    for (int i=1;i<=n;i++){
        cin >> a[i];
        ll x = a[i];
        for (int j=0;j<31;j++){
            pre[j][i] = pre[j][i-1] + x%2;
            x >>= 1;
        }
    }
    while (m--){
        int l,r;
        cin >> l >> r;
        string s = "";
        for (int i=0;i<31;i++){
            if (pre[i][r]-pre[i][l-1]==r-l+1){
                s.push_back('1');
            } else{
                s.push_back('0');
            }
        }
        reverse(s.begin(),s.end());
        cout << BtoD(s) << '\n';
    }
}