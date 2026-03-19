#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    LL n;
    cin >> n;
    vector<int> ans;
    int vis[n+1];
    int x = 0;
    int ok = 1;
    for (int i=0;i<=n;i++) vis[i] = 0;
    vis[0] = 1;
    while (n){
        x = 0;
        while ((1LL << x + 1) <= n){
            x ++;
        }
        n -= (1LL << x);
        if (vis[x]) ok = 0;
        vis[x] = 1;
        ans.push_back(x);
    }
    if (ok){
        sort(ans.begin(),ans.end(),[&](int x,int y){
            return x > y;
        });
        for (int i=0;i<ans.size();i++){
            cout << (1LL << ans[i]) << " \n"[i==ans.size()-1];
        }
    } else{
        cout << -1 << '\n';
    }
}