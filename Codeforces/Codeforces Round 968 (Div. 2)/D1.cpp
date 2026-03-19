#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n,m;
        cin >> n >> m;
        ll Max = 0;
        for (int i=0;i<n;i++){
            ll l,x;
            cin >> l;
            map<int,int> mp;
            ll mx = 0;
            for (int i=0;i<l;i++){
                cin >> x;
                mp[x] ++;
                mx = max(mx,x);
            }
            ll cnt = 0,mex;
            for (int i=0;i<=mx+2;i++){
                if (!mp[i]){
                    cnt ++;
                }
                if (cnt==2){
                    mex = i;
                    break;
                }
            }
            Max = max(mex,Max);
        }
        if (Max > m){
            cout << (m+1) * Max << '\n';
        } else{
            cout << (Max+1) * Max + (Max+m+1)*(m-Max)/2 << '\n';
        }
    }
}