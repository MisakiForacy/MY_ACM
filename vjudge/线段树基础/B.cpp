#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,m,l,r;
    cin >> n >> m;
    int st[n+1][21];
    for (int i=1;i<=n;i++){
        cin >> st[i][0];
    }
    for (int i=1;i<=20;i++){
        for (int j=1;j+(1LL << i)-1 <= n;j++){
            st[j][i] = min(st[j][i-1],st[j+(1LL << i-1)][i-1]);
        }
    }
    vector<int> ans;
    while (m--){
        cin >> l >> r;
        int k = log2(r-l+1);
        ans.push_back(min(st[l][k],st[r-(1LL << k)+1][k]));
    }
    for (int i=0;i<ans.size();i++){
        cout << ans[i] << " \n"[i==ans.size()-1];
    }
}