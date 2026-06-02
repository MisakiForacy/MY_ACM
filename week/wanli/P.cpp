#include <bits/stdc++.h>
#define mod (ll)(1e9+7)
// #define endl '\n'
using namespace std;
typedef long long ll;
ll p(ll ds,ll cf);
ll inv(ll x);
ll m(ll a,ll b);
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);
    ll nn,x,t;
    // while(scanf("%d",&nn)!=EOF){
    cin >> nn;
    while(nn--){
        cin >> x;
        x = x % mod;
        t = m((m(-14,p(m(x,m((x+1),inv(2))),2))+m((m(6,x)+15),(m(m(x,(x+1)),m((m(2,x)+1),inv(6)))))+m((m(6,x)-1),(m(m(x,(x+1)),inv(2))))+m(8,p(x,4))+m(9,p(x,3))+p(x,2)),inv(6));
        cout << t % mod << endl;
    }
    // }
}
ll p(ll ds,ll cf){
    ll sum=1;
    while(cf>0){
        if(cf%2==1)sum=(sum*ds)%mod;
        ds=(ds*ds)%mod;
        cf/=2;
    }
    return sum;
}
ll m(ll a,ll b){
    ll c;
    return ((a % mod)*(b % mod)) % mod; 
}
ll inv(ll x){
    return p(x,mod-2);
}