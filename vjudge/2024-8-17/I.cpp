#include <bits/stdc++.h>
using namespace std;
int n,m,k;
bool check(vector<vector<int>> mp){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            mp[i][j] += mp[i-1][j] + mp[i][j-1] - mp[i-1][j-1];
        }
    }
    // for (int i=1;i<=n;i++){
    //     for (int j=1;j<=m;j++){
    //         cout << mp[i][j] << " \n"[j==m];
    //     }
    // }
    // cout << '\n';
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (!mp[i][j]){
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    cin >> n >> m >> k;
    vector<vector<int>> mp(n+2,vector<int>(m+2,0));
    vector<int>x1(k),y1(k),x2(k),y2(k);
    for (int i=0;i<k;i++){
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        mp[x1[i]][y1[i]] += 1;
        mp[x2[i]+1][y1[i]] -= 1;
        mp[x1[i]][y2[i]+1] -= 1;
        mp[x2[i]+1][y2[i]+1] += 1;
    }
    if (!check(mp)){
        cout << -1 << '\n';
    } else{
        int lo = 1, hi = k;
        while (lo <= hi){
            int mid = (lo+hi) >> 1;
            vector<vector<int>> mp(n+2,vector<int>(m+2,0));
            for (int i=0;i<mid;i++){
                mp[x1[i]][y1[i]] += 1;
                mp[x2[i]+1][y1[i]] -= 1;
                mp[x1[i]][y2[i]+1] -= 1;
                mp[x2[i]+1][y2[i]+1] += 1;
            }
            if (check(mp)) hi = mid - 1;
            else lo = mid + 1;
            // cout << mid << ' ' << lo << ' ' << hi << '\n';
        }
        cout << lo << '\n';
    }
}