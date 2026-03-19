#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        string a,b;
        int n,q,l,r;
        cin >> n >> q;
        cin >> a >> b;
        vector<vector<int>>prea(27,vector<int>(n+1,0));
        vector<vector<int>>preb(27,vector<int>(n+1,0));
        for (int i=1;i<=n;i++){
            for (int j=0;j<26;j++){
                if (j==a[i-1]-'a'){
                    prea[j][i] = prea[j][i-1] + 1;
                } else{
                    prea[j][i] = prea[j][i-1];
                }
                if (j==b[i-1]-'a'){
                    preb[j][i] = preb[j][i-1] + 1;
                } else{
                    preb[j][i] = preb[j][i-1];
                }
            }
        }
        for (int i=0;i<q;i++){
            cin >> l >> r;
            int cnt,cnta,cntb;
            cnt = cnta = cntb = 0;
            for (int j=0;j<26;j++){
                cnta = prea[j][r] - prea[j][l-1];
                cntb = preb[j][r] - preb[j][l-1];
                cnt += abs(cnta - cntb);
            }
            cout << cnt/2 + cnt%2 << '\n';
        }
    }
}