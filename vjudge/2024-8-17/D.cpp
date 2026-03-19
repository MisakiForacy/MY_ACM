#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    vector<vector<ll>> pre(31,vector<ll>(2e5+5,0));
    for (int i=1;i<=2e5;i++){
        ll x = i;
        for (int j=0;j<31;j++){
            pre[j][i] = pre[j][i-1] + x%2;
            x >>= 1;
        }
    }
    while (T--){
        int l,r;
        cin >> l >> r;
        int mi = r-l+1;
        for (int i=0;i<31;i++){
            if (((r-l+1)-(pre[i][r]-pre[i][l-1]))<mi){
                mi = (r-l+1)-(pre[i][r]-pre[i][l-1]);
            }
        }
        cout << mi << '\n';
    }
}