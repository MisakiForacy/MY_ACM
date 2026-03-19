#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> c(n);
    for (int i=0;i<n;i++) cin >> c[i];
    sort(c.begin(),c.end());
    vector<int>vis(n,0);
    vector<int>ans;
    ans.push_back(c[0]);
    vis[0] = 1;
    while (ans.size()!=n){
        for (int i=0;i<n;i++){
            if (c[i]!=c[ans.back()-1] && !vis[i]){
                ans.push_back(i+1);
                vis[i] = 1;
            }
        }
    }
    for (int i=0;i<n;i++){
        cout << ans[i] << '\n';
    }
}