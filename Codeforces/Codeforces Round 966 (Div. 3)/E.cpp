#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(ll a,ll b){
    return a > b;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        ll n,m,k;
        cin >> n >> m >> k;
        vector<ll>row(n+2,0),cal(m+2,0);
        for (int i=1;i<=n-k+1;i++){
            row[i] += 1;
            row[i+k] -= 1;
        }
        for (int j=1;j<=m-k+1;j++){
            cal[j] += 1;
            cal[j+k] -= 1;
        }
        for (int i=1;i<=n;i++){
            row[i] = row[i] + row[i-1];
            // cout << row[i] << " \n"[i==n];
        }
        for (int j=1;j<=m;j++){
            cal[j] = cal[j] + cal[j-1];
            // cout << cal[j] << " \n"[j==m];
        }
        vector<ll>mut;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                mut.push_back(row[i]*cal[j]);
            }
        }
        
        sort(mut.begin(),mut.end(),cmp);
        // for (int i=0;i<mut.size();i++){
        //     cout << mut[i] << " \n"[i==mut.size()-1];
        // }
        int w;
        cin >> w;
        vector<ll>x(w);
        ll ans = 0;
        for (int i=0;i<w;i++){
            cin >> x[i];
        }
        sort(x.begin(),x.end(),cmp);
        for (int i=0;i<w;i++){
            ans += mut[i] * x[i];
        }
        cout << ans << '\n';
    }
}