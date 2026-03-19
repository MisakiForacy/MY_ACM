#include <bits/stdc++.h>
#define debug(x) cerr << #x << ":" << x << '\n'
using namespace std;
using LL = long long;
void solve(){
    map<int,int> mp;
    int x,n;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> x;
        mp[x] ++;
    }
    int ans = 0;
    for (auto [k,v]:mp){
        ans += v / 2;
    }
    cout << ans << '\n';
    return;
}
int main(){
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
}