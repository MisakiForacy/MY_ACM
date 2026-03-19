#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        ll x,y,k;
        cin >> x >> y >> k;
        ll sx = 0, sy = 0;
        vector<pair<ll,ll>>ans;
        for (int i=1;i<k;i++){
            ans.push_back({x+i,y+i});
            sx += (x+i);
            sy += (y+i);
        }
        ans.push_back({x*k-sx,y*k-sy});
        for (int i=0;i<k;i++){
            cout << ans[i].first << ' ' << ans[i].second << '\n';
        }
    }
}