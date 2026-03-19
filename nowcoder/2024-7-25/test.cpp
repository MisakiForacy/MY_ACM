#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,n;
    int f[4];
    f[1] = f[2] = 1;
    while (cin >> a >> b >> n){
        if (!(a&&b&&n)) break;
        int len = 1e9;
        vector<int>ans;
        ans.push_back(1);
        ans.push_back(1);
        f[1] = f[2] = 1;
        for (int i=3;i<=n;i++){
            if (i!=3 && ans[ans.size()-1]==1 && ans[ans.size()-2]==1){
                len = i-2;
                break;
            }
            f[3] = (a*f[2]+b*f[1])%7;
            f[1] = f[2], f[2] = f[3];
            ans.push_back(f[3]);
        }
        // for (int i=0;i<ans.size();i++){
        //     cout << ans[i] << ' ';
        // }
        // cout << '\n';
        // cout << len << '\n';
        cout << ans[min(n-1,n%len)] << '\n';
    }
}