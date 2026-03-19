#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        map<int,int> rec;
        vector<vector<int>> mp(n+1,vector<int>(n+1,0));
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                cin >> mp[i][j];
                if (mp[i][j]<0){
                    rec[j-i] = min(rec[j-i],mp[i][j]);
                }
            }
        }
        LL ans = 0;
        for (auto [k,v]:rec){
            ans -= v;
        }
        cout << ans << '\n';
    }
}