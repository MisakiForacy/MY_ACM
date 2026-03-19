#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,k;
        cin >> n >> k;
        map<int,LL> mp;
        LL b, c;
        for (int i=0;i<k;i++){
            cin >> b >> c;
            mp[b] += c;
        }
        vector<LL> a;
        for (auto [k,v]:mp){
            a.push_back(v);
        }
        sort(a.begin(),a.end(),[&](LL x,LL y){
            return x > y;
        });
        LL ans = 0;
        for (int i=0;i<min(n,(int)a.size());i++){
            ans += a[i];
        }
        cout << ans << '\n';
    }
}