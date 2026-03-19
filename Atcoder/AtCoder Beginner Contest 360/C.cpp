#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,ans=0;
    cin >> n;
    vector<ll>a(n+1);
    vector<ll>w(n+1);
    vector<vector<ll>>b(n+1);
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    for (int i=1;i<=n;i++){
        cin >> w[i];
        b[a[i]].push_back(w[i]);
    }
    for (int i=1;i<=n;i++){
        if (b[i].size()){
            sort(b[i].begin(),b[i].end());
            for (int j=0;j<b[i].size()-1;j++){
                ans += b[i][j];
            }
        }
    }
    cout << ans << '\n';
}