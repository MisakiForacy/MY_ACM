#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll qpower(ll a,ll k){
    ll res = 1;
    while (k){
        if (k&1) res = res * a;
        a = a * a;
        k >>= 1;
    }
    return res;
}
int main(){
    int n,t;
    cin >> n >> t;
    vector<int> a(n);
    map<int,int>mp;
    for (int i=0;i<n;i++){
        cin >> a[i];
        mp[a[i]%qpower(10,t)] ++;
    }
    int cnt = 0;
    for (auto c:mp){
        cnt ++;
    }
    cout << cnt << '\n';
}