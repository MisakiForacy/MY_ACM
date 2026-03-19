#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        ll n,ans=0;
        vector<map<pair<ll,ll>,vector<ll>>>ar(3);
        cin >> n;
        ll a[3];
        cin >> a[0] >> a[1] >> a[2];
        ar[0][{a[1],a[2]}].push_back(a[0]);
        ar[1][{a[0],a[2]}].push_back(a[1]);
        ar[2][{a[0],a[1]}].push_back(a[2]);
        for (int i=3;i<n;i++){
            a[0] = a[1];
            a[1] = a[2];
            cin >> a[2];
            ar[0][{a[1],a[2]}].push_back(a[0]);
            ar[1][{a[0],a[2]}].push_back(a[1]);
            ar[2][{a[0],a[1]}].push_back(a[2]);
        }
        for (int i=0;i<3;i++){
            for (auto k:ar[i]){
                sort(k.second.begin(),k.second.end());
                ll kk = 0;
                for (int j=0;j<(ll)k.second.size();j++){
                    if (j>0 && k.second[j]==k.second[j-1]){
                        kk ++;
                    } else{
                        kk = 0;
                    }
                    ans += j - kk;
                }
            }
        }
        cout << ans << '\n';
    }
}