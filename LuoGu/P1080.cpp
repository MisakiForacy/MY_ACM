#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
struct haha{
    ll le,ri;
};
bool cmp(haha aa,haha bb){
    if (aa.le*aa.ri==bb.le*bb.ri) return aa.le<bb.ri;
    return (aa.le*aa.ri)<(bb.le*bb.ri);
}
int main(){
    ll n,kl,kr,mx = 0;
    cin >> n;
    cin >> kl >> kr;
    vector<haha>a(n);
    for (int i=0;i<n;i++){
        cin >> a[i].le >> a[i].ri;
    }
    sort(a.begin(),a.end(),cmp);
    ll multi = kl;
    for (auto c:a){
        mx = max(mx,multi/c.ri);
        multi *= c.le;
    }
    cout << mx << '\n';
}