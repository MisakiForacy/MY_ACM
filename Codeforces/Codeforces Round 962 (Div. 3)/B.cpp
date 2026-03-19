#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,k;
        cin >> n >> k;
        string s;
        vector<vector<int>>mp(n,vector<int>(n));
        for (int i=0;i<n;i++){
            cin >> s;
            for (int j=0;j<n;j++){
                mp[i][j] = s[j] - '0';
            }
        }
        vector<vector<int>>ans(n/k,vector<int>(n/k));
        for (int i=0;i<n;i+=k){
            for (int j=0;j<n;j+=k){
                ans[i/k][j/k] = mp[i][j];
            }
        }
        for (int i=0;i<n/k;i++){
            for (int j=0;j<n/k;j++){
                cout << ans[i][j];
            }
            cout << '\n';
        }
    }
}