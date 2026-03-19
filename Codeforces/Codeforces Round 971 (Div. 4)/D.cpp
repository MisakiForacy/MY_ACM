#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,x,y;
        cin >> n;
        vector<vector<int>> mp(n+2,vector<int>(2,0));
        set<int> l1,l2;
        for (int i=0;i<n;i++) {
            cin >> x >> y;
            mp[x][y] = 1;
            if (y==0)l1.insert(x);
            if (y==1)l2.insert(x);
        }
        ll len1 = l1.size();
        ll len2 = l2.size();
        ll cnt = 0;
        for (int i=0;i<=n+1;i++){
            int ok = 0;
            if (mp[i][0] && mp[i][1]){
                cnt += len1 + len2 - 2;
                ok = 1;
            }
            if (i>0 && mp[i][1] && mp[i-1][0] && mp[i+1][0]){
                cnt ++;
                ok = 1;
            }
            if (i>0 && mp[i][0] && mp[i-1][1] && mp[i+1][1]){
                cnt ++;
                ok = 1;
            }
        }
        cout << cnt << '\n';
    }
}