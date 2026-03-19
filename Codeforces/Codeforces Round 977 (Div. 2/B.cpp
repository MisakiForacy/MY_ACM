#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        LL n,x;
        LL Max = LLONG_MIN;
        cin >> n >> x;
        vector<LL> a(n);
        map<LL,LL> mp;
        for (int i=0;i<n;i++){
            cin >> a[i];
            Max = max(Max,a[i]);
            mp[a[i]] ++;
        }
        LL mex = 0;
        for (int i=0;i<=Max+1;i++){
            if (!mp[i]){
                mex = i;
                break;
            } else if (mp[i]>1){
                mp[i+x] += mp[i] - 1;
                Max = max(Max,(LL)i+x);
            }
        }
        cout << mex << '\n';
    }
}