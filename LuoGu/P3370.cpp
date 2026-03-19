#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const ull mod = 1e17+9;
const int P = 13331;
map<ull,int>mp;
ll qpower(ll a,ll x){
    ll res = 1;
    while (x){
        if (x&1) res = res * a % mod;
        a = a * a % mod;
        x >>= 1;
    }
    return res;
}
ull get(string s){
    ull hash = 0;
    int n = s.length();
    for (int i=0;i<n;i++){
        hash += s[i]*qpower(P,n-i-1)%mod;
    }
    return hash;
}
int main(){
    int t,cnt = 0;
    string s;
    cin >> t;
    while (t--){
        cin >> s;
        mp[get(s)]++;
    }
    for (auto c:mp){
        cnt ++;
    }
    cout << cnt << '\n';
}