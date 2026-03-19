#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int> a(n+1), vis(n+1,-1);
        string s;
        for (int i=1;i<=n;i++) cin >> a[i];
        cin >> s; s = ' ' + s;
        for (int i=1;i<=n;i++){
            if (vis[i]==-1){    
                int beg = i,p=i,cnt = 0;
                while (a[p]!=beg){
                    cnt += (s[p]=='0');
                    p = a[p];
                }
                cnt += (s[p]=='0');
                p = i;
                while (a[p]!=beg){
                    vis[p] = cnt;
                    p = a[p];
                }
                vis[p] = cnt;
            }
        }
        for (int i=1;i<=n;i++){
            cout << vis[i] << " \n"[i==n];
        }
    }
}