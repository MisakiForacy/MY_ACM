#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,m;
        cin >> n >> m;
        vector<vector<int>>mp(n,vector<int>(m));
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                cin >> mp[i][j];
            }
        }
        if (n==1 && m==1){
            cout << -1 << '\n';
        } else{
            for (int i=0;i<n;i++){
                for (int j=0;j<m;j++){
                    cout << mp[(i+1)%n][(j+1)%m] << " \n"[j==m-1];
                }
            }
        }
    }
}