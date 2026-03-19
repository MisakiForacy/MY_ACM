#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n,ans;
        cin >> n;
        vector<ll>ar(n+1,0),br(n+1,0);
        vector<ll>d;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
            if (ar[i]<br[i-1]){
                br[i] = br[i-1];
                d.push_back(abs(br[i]-ar[i]));
            } else{
                br[i] = ar[i];
            }
        }
        d.push_back(0);
        sort(d.begin(),d.end());
        ans = 0;
        for (int i=1;i<d.size();i++){
            ans += (d[i]-d[i-1])*(d.size()-i+1);
        }
        cout << ans << '\n';
    }
}