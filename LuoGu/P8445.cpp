#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    vector<int> b(n+1,0);
    vector<vector<int>> mp(n+1);
    for (int i=0;i<=n;i++){
        mp[i].push_back(0);
    }
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++){
        cin >> b[i];
        if (a[i] == b[i]){
            mp[a[i]].push_back(i);
        }
    }
    for (int i=0;i<=n;i++){
        if (mp[i].back()!=n) mp[i].push_back(n);
    }
    int ans = 0;
    for (int i=0;i<=n;i++){
        // cout << i << " : ";
        // ans = 0;
        for (int j=1;j<mp[i].size();j++){
            ans = max(ans,mp[i][j]-mp[i][j-1]-i);
        }
        // cout << ans << '\n';
    }
    cout << ans << '\n';
}