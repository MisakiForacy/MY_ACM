#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n,k;
        cin >> n >> k;
        vector<ll> a(n+1);
        vector<ll> pre(n+1,0);
        vector<ll> cnt(n+1,0);
        for (int i=1;i<=n;i++){
            cin >> a[i];
            pre[i] = pre[i-1] + a[i];
            cnt[i] = cnt[i-1] + (a[i]==1);
        }
        ll l,r;
        for (int i=0;i<k;i++){
            cin >> l >> r;
            ll sum = pre[r] - pre[l-1];
            ll num = cnt[r] - cnt[l-1];
            if ((r-l+1)+num<=sum && r!=l){
                cout << "YES\n";
            } else{
                cout << "NO\n";
            }
        }
    }
}