#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,k,m;
        string s;
        cin >> n >> k >> m;
        cin >> s;
        s = ' ' + s;
        vector<vector<int>> pre(k+1,vector<int>(m+1,0));
        vector<vector<int>> vis(k+1,vector<int>(n+1,0));
        for (int i=1;i<=m;i++){
            pre[s[i]-'a'+1][i] ++;
            for (int j=1;j<=k;j++){
                pre[j][i] += pre[j][i-1];
            }
        }
        for (int i=1;i<=m;i++){
            for (int t=max(1,n-m+i);t<=min(n,i);t++){
                int ok = 1;
                for (int j=1;j<=k;j++){
                    if (pre[j][i-1]-pre[j][0]<t-1 || pre[j][m]-pre[j][i]<n-t){
                        ok = 0;
                    }
                }
                vis[s[i]-'a'+1][t] = max(vis[s[i]-'a'+1][t],ok);
            }
        }
        int ok = 1;
        string bad = "";
        for (int ii=1;ii<=k;ii++){
            for (int t=1;t<=n;t++){
                if (!vis[ii][t]){
                    ok = 0;
                    vector<vector<int>> enable(k+1,vector<int>(k+1,0));
                    for (int i=1;i<=m;i++){
                        if (s[i]-'a'+1==ii && t>=max(1,n-m+i) && t<=min(n,i)){
                            for (int j=1;j<=k;j++){
                                for (int l=1;l<=k;l++){
                                    if (pre[j][i-1]-pre[j][0]>=t-1 && pre[l][m]-pre[l][i]>=n-t){
                                        enable[j][l] = 1;
                                    }
                                }
                            }
                        }
                    }
                    for (int i=1;i<=k;i++){
                        for (int j=1;j<=k;j++){
                            if (!enable[i][j]){
                                for (int n1=0;n1<t-1;n1++){
                                    bad.push_back(i+'a'-1);
                                }
                                bad.push_back(ii+'a'-1);
                                for (int n2=0;n2<n-t;n2++){
                                    bad.push_back(j+'a'-1);
                                }
                                goto end;
                            }
                        }
                    }
                }
            }
        }
        end:;
        if (ok){
            cout << "YES\n";
        } else{
            cout << "NO\n";
            cout << bad << '\n';
        }
    }
}