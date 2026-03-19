#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,m,b,p;
        cin >> n >> m;
        vector<int> res(m+1,0);
        vector<vector<int>> op(n);
        vector<vector<int>> besket(m+1);
        for (int i=0;i<n;i++){
            cin >> p;
            for (int j=0;j<p;j++){
                cin >> b;
                res[b] = i;
                op[i].push_back(b);

            }
        }
        
        for (int i=1;i<=m;i++){
            cout << res[i] << " \n"[i==m];
        }
    }
}