#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,x;
        cin >> n;
        map<int,int> mp;
        for (int i=0;i<n;i++){
            cin >> x;
            mp[x] ++;
        }
        int ans = 0;
        int cnt = 0;
        for (auto [k,v]:mp){
            if (v > 1) ans ++;
            else cnt ++;
        }
        ans += (cnt/2 + cnt%2) * 2;
        cout << ans << '\n';
    }
}