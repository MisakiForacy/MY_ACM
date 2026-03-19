#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n, x, mx = 0;
        cin >> n;
        map<int,int>mp;
        for (int i=0;i<n;i++){
            cin >> x;
            mp[x] ++;
            mx = max(mx,mp[x]);
        }
        // cout << mx << ':';
        int k = 0, t = mx;
        int res = n - mx;
        while (res > 0){
            res -= t;
            t *= 2;
            k ++;
        }
        cout << (n-mx) + k << '\n';
    }
}