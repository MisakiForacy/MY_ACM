#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long i64;
i64 t,n,k,pb,ps,i,mx1,mx2,cur1,cur2,s1,s2;
vector<i64>a,p;
void solve();
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
void solve(){
    mx1 = mx2 = cur1 = cur2 = 0;
    cin >> n >> k >> pb >> ps;
    s1 = s2 = k;
    a.resize(n+1),p.resize(n+1);
    for(i=1;i<=n;i++)cin >> p[i];
    for(i=1;i<=n;i++)cin >> a[i];
    vector<bool>va1(n+1,true),va2(n+1,true);
    while(va1[pb]&&s1>0){
        va1[pb] = false;
        mx1 = max(mx1,cur1+s1*a[pb]);
        cur1 += a[pb];
        pb = p[pb];
        s1--;
    }
    while(va2[ps]&&s2>0){
        va2[ps] = false;
        mx2 = max(mx2,cur2+s2*a[ps]);
        cur2 += a[ps];
        ps = p[ps];
        s2--;
    }
    cout << (mx1>mx2?"Bodya":mx1<mx2?"Sasha":"Draw") << endl;
}