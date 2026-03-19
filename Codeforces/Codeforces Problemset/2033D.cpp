#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<LL> a(n+1,0), pre(n+1,0);
        for (int i=1;i<=n;i++){
            cin >> a[i];
            pre[i] = pre[i-1] + a[i];
        }
        map<LL,LL> mp;
        LL cnt = 0;
        for (int i=0;i<=n;i++){
            if (!mp[pre[i]]){
                mp[pre[i]] ++;
            } else if (mp[pre[i]]){
                mp.clear();
                cnt ++;
                mp[pre[i]] ++;
            }
        }
        cout << cnt << '\n';
    }
}