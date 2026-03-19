#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,m;
        cin >> n >> m;
        vector<vector<char>> mp(n+2,vector<char>(m+2));
        string s;
        for (int i=1;i<=n;i++){
            cin >> s;
            for (int j=1;j<=m;j++){
                mp[i][j] = s[j-1];
            }
        }
        int ok = 1;
        for (int i=1;i<=n;i++){
            int cnt = 0;
            for (int j=1;j<=m;j++){
                if (mp[i][j]=='U' || mp[i][j]=='D'){
                    cnt ++;
                }
            }
            if (cnt&1){
                ok = 0;
            }
        }
        for (int j=1;j<=m;j++){
            int cnt = 0;
            for (int i=1;i<=n;i++){
                if (mp[i][j]=='L' || mp[i][j]=='R'){
                    cnt ++;
                }
            }
            if (cnt&1){
                ok = 0;
            }
        }
        if (ok){
            int f = 0;
            for (int i=1;i<=n;i++){
                for (int j=1;j<=m;j++){
                    if (mp[i][j]=='U'){
                        mp[i][j] = (f?'W':'B');
                        f = (f?0:1);
                    }
                    if (mp[i+1][j]=='D'){
                        mp[i+1][j] = (f?'W':'B');
                    }
                }
            }
            f = 0;
            for (int j=1;j<=m;j++){
                for (int i=1;i<=n;i++){
                    if (mp[i][j]=='L'){
                        mp[i][j] = (f?'W':'B');
                        f = (f?0:1);
                    }
                    if (mp[i][j+1]=='R'){
                        mp[i][j+1] = (f?'W':'B');
                    }
                }
            }
            for (int i=1;i<=n;i++){
                for (int j=1;j<=m;j++){
                    cout << mp[i][j];
                }
                cout << '\n';
            }
        } else{
            cout << -1 << '\n';
        }
    }
}