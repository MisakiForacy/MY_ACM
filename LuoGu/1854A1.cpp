#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<pair<int,int>> ans;
        vector<LL> a(n+1);
        int idx;
        LL Max = LLONG_MIN;
        LL Min = LLONG_MAX;
        for (int i=1;i<=n;i++){
            cin >> a[i];
            Min = min(Min,a[i]);
            if (Max < a[i]){
                Max = a[i];
                idx = i;
            }
        }
        if (Max > 0){
            if (Min < 0){
                while (Max+Min < 0){
                    a[idx] *= 2;
                    Max *= 2;
                    ans.push_back({idx,idx});
                }
            }
            for (int i=1;i<=n;i++){
                if (a[i] < 0){
                    a[i] += Max;
                    ans.push_back({i,idx});
                }
            }
            for (int i=2;i<=n;i++){
                if (a[i] < a[i-1]){
                    a[i] += a[i-1];
                    ans.push_back({i,i-1});
                }
            }
            cout << ans.size() << '\n';
            for (int i=0;i<ans.size();i++){
                cout << ans[i].first << ' ' << ans[i].second << '\n';
            }
        } else{
            for (int i=n-1;i>=1;i--){
                if (a[i] > a[i+1]){
                    a[i] += a[i+1];
                    ans.push_back({i,i+1});
                }
            }
            cout << ans.size() << '\n';
            for (int i=0;i<ans.size();i++){
                cout << ans[i].first << ' ' << ans[i].second << '\n';
            }
        }
    }
}