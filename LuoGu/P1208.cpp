#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct haha{
    int p,x;
};
bool cmp(haha a,haha b){
    return a.p < b.p;
}
int main(){
    ll n,m,ans = 0;
    cin >> n >> m;
    vector<haha>a(m);
    for (int i=0;i<m;i++){
        cin >> a[i].p >> a[i].x;
    }
    sort(a.begin(),a.end(),cmp);
    for (auto c:a){
        if (c.x <= n){
            ans += c.x * c.p;
            n -= c.x;
        } else{
            ans += n * c.p;
            n = 0;
        }
    }
    cout << ans << '\n';
}