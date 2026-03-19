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
        vector<int> cir;
        vector<int> vis(n+1,0);
        for (int i=1;i<=n;i++){
            cin >> a[i];
        }
        int siz = 0;
        for (int i=1;i<=n;i++){
            int id = i;
            while (!vis[id]){
                vis[id] = 1;
                id = a[id];
                siz ++;
            }
            if (siz){
                cir.push_back(siz);
                siz = 0;
            }
        }
        LL ans = 0;
        for (int i=0;i<cir.size();i++){
            ans += (cir[i]-1) / 2;
        }
        cout << ans << '\n';
    }
}