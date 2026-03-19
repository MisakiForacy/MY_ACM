#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<pair<pair<ll,ll>,ll>,ll>mp;
ll w(ll a,ll b,ll c){
    ll ans;
    if (mp[{{a,b},c}]) return mp[{{a,b},c}];
    if (a<=0||b<=0||c<=0){
        return 1;
    } else if (a>20||b>20||c>20){
        ans = w(20,20,20);
        mp[{{a,b},c}] = ans;
        return ans;
    } else if (a < b && b < c){
        ans = w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
        mp[{{a,b},c}] = ans;
        return ans;
    } else{
        ans = w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
        mp[{{a,b},c}] = ans;
        return ans;
    }
}
int main(){
    ll a,b,c;
    while (cin >> a >> b >> c){
        if (a==-1 && b==-1 && c==-1){
            break;
        }
        ll ans = w(a,b,c);
        printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,ans);
    }
}