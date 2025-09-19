#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int k;
    cin >> k;
    vector<vector<int>> a(k + 1);
    map<int,pair<int,int>> mp;
    for (int i = 1;i <= k;i ++){
        int n;
        cin >> n;
        a[i].resize(n + 1,0);
        LL sum = 0;
        for (int j = 1;j <= n;j ++){
            cin >> a[i][j];
            sum += a[i][j];
        }
        for (int j = 1;j <= n;j ++){
            if (mp.count(sum - a[i][j]) && mp[sum - a[i][j]].first != i){
                cout << "YES\n";
                cout << mp[sum - a[i][j]].first << ' ' << mp[sum - a[i][j]].second << '\n';
                cout << i << ' ' << j << '\n';
                return 0;
            } else if (!mp.count(sum - a[i][j])){
                mp[sum - a[i][j]] = {i,j};
            }
        }
    }
    cout << "NO\n";
}