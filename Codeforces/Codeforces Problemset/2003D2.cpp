#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,m;
        cin >> n >> m;
        vector<vector<int>> mp(n+1);
        for (int i=1;i<=n;i++){
            int l;
            cin >> l;
            mp[i].resize(l);
            for (int j=0;j<l;j++){
                cin >> mp[i][j];
            }
        }
        
    }
}