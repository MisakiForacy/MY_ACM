#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll T,n,m;
    bool flg;
    cin >> T;
    while (T --){
        cin >> n;
        vector<ll>a(n+1);
        vector<ll>b(n+1);
        vector<ll>c;
        for (int i=1;i<=n;i++) cin >> a[i];
        for (int i=1;i<=n;i++){
            cin >> b[i];
            if (a[i] != b[i]){
                c.push_back(b[i]);
            }
        }
        cin >> m;
        vector<ll>d(m+1);
        for (int i=1;i<=m;i++){
            cin >> d[i];
        }
        if (find(b.begin()+1,b.end(),d[m]) == b.end()){
            cout << "NO\n";
        } else{
            flg = true;
            sort(c.begin(),c.end());
            sort(d.begin()+1,d.end());
            int j = 1;
            for (int i=0;i<c.size();i++){
                while (j<=m && d[j] != c[i]) j++;
                if (d[j] == c[i]){
                    j ++;
                } else{
                    cout << "NO\n";
                    flg = false;
                    break;
                }
            }
            if (flg){
                cout << "YES\n";
            }
        }
    }
}