#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n-1);
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n-1;i++) cin >> b[i];
    sort(a.begin(),a.end(),[&](int x,int y){
        return x > y;
    });
    sort(b.begin(),b.end(),[&](int x,int y){
        return x > y;
    });
    int k = 0;
    int vis[n+1];
    memset(vis,0,sizeof(vis));
    for (int i=0;i<n-1;i++){
        while (k<n && a[k] > b[i]) k ++;
        if (k == n) break;
        if (b[i] >= a[k]) vis[k] = 1;
        k ++;
    }
    int ans,cnt = 0;
    for (int i=0;i<n;i++){
        if (!vis[i]) ans = a[i],cnt ++;
    }
    if (cnt > 1) ans = -1;
    cout << ans << '\n';
}