#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,k,q;
    while (cin >> n >> k >> q){
        vector<vector<int>>pre(k,vector<int>(n+1,0));
        for (int i=0;i<k;i++){
            for (int j=1;j<=n;j++){
                cin >> pre[i][j];
                pre[i][j] = pre[i][j-1] + pre[i][j];
            }
        }
        int lo,hi;
        for (int i=0;i<q;i++){
            cin >> lo >> hi;
            int mx = 0;
            for (int j=0;j<k;j++){
                mx = max(mx,pre[j][hi]-pre[j][lo-1]);
            }
            cout << mx << '\n';
        }
    }
}