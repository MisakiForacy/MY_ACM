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
string get_bit(ll n){
    string s = "";
    while (n){
        s.push_back((n%2?'1':'0'));
        n >>= 1;
    }
    reverse(s.begin(),s.end());
    return s;
}
int count(ll n){
    int cnt = 0;
    while (n){
        cnt += (n%2?1:0);
        n >>= 1;
    }
    return cnt;
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
    ll n;
    cin >> n;
    string bit = get_bit(n);
    int len = bit.length();
    int cnt = count(n);
    // cout << bit << ' ' << len << ' ' << cnt << '\n';
    if (cnt >= len - 1){
        cout << n << '\n';
    } else if (bit[1]=='1'){
        string ans_bit = "";
        ans_bit.push_back('1');
        ans_bit.push_back('0');
        for (int i=0;i<len-2;i++){
            ans_bit.push_back('1');
        }
        ll ans = BtoD(ans_bit);
        cout << ans << '\n';
    } else{
        ll x = 1;
        while (x*2<=n) x *= 2;
        cout << x - 1 << '\n';
    }
}