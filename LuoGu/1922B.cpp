#include <bits/stdc++.h>
#define debug(x) cerr << #x << ':' << x << '\n'
using namespace std;
typedef long long ll;
ll C(ll n,ll m){
    ll res = 1;
    for (int i=m;i>m-n;i--){
        res *= i;
    }
    for (int i=2;i<=n;i++){
        res /= i;
    }
    return res;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int> a(n);
        map<int,int> mp;
        set<int> st;
        for (int i=0;i<n;i++){
            cin >> a[i];
            mp[a[i]] ++;
            st.insert(a[i]);
        }
        sort(a.begin(),a.end());
        ll ans = 0;
        ll pre = 0;
        for (int x:st){
            if (mp[x]>=2){
                ans += C(2,mp[x])*pre;
            }
            if (mp[x]>=3){
                ans += C(3,mp[x]);
            }
            pre += mp[x];
        }
        cout << ans << '\n';
    }
}