#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    while(cin >> n >> m){
        vector<vector<int>> mp = {{1,1,1,3},
                            {2,1,3,3},
                            {2,2,4,3},
                            {2,4,4,4}};
        vector<vector<int>> ans(n,vector<int>(m));
        if (n%4 || m%4){
            cout << "no response\n";
        } else{
            for (int i=0;i<n;i+=4){
                for (int j=0;j<m;j+=4){
                    for (int k=0;k<4;k++){
                        for (int t=0;t<4;t++){
                            ans[i+k][j+t] = mp[k][t];
                        }
                    }
                }
            }
            for (int i=0;i<n;i++){
                for (int j=0;j<m;j++){
                    cout << ans[i][j];
                }
                cout << '\n';
            }
        }
    }
}