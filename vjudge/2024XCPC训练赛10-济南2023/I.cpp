#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int> a(n+1,0);
        for (int i=1;i<=n;i++){
            cin >> a[i];
        }
        vector<pair<int,int>> ans;
        for (int i=n;i>=1;i--){
            for (int j=1;j<i;j++){
                if (a[j] > a[i]){
                    ans.push_back({j,i});
                    sort(a.begin()+j,a.begin()+i);
                    break;
                }
            }
        }
        cout << ans.size() << '\n';
        for (int i=0;i<ans.size();i++){
            cout << ans[i].first << ' ' << ans[i].second << '\n';
        }
    }
}