#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,ans = 0;
    cin >> n;
    vector<ll>h(n+1,0);
    for (int i=1;i<=n;i++){
        cin >> h[i];
    }
    sort(h.begin(),h.end());
    vector<ll>a;
    ll p1 = 0, p2 = n;
    int f = 1;
    while (p1 <= p2){
        if (f){
            a.push_back(h[p1]);
            p1 ++;
            f = !f;
        } else{
            a.push_back(h[p2]);
            p2 --;
            f = !f;
        }
    }
    for (int i=1;i<=n;i++){
        ans += (a[i]-a[i-1])*(a[i]-a[i-1]);
    }
    cout << ans << '\n';
}