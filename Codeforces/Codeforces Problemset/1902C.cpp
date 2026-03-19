#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<LL> a(n+1,LLONG_MIN);
        map<LL,int> mp;
        for (int i=1;i<=n;i++){
            cin >> a[i];
            mp[a[i]] = 1;
        }
        sort(a.begin(),a.end());
        if (n!=1){   
            vector<LL> diff(n+1);
            diff[1] = a[2] - a[1];
            LL gcd = diff[1];
            for (int i=3;i<=n;i++){
                diff[i] = a[i] - a[i-1];
                gcd = __gcd(gcd,diff[i]);
            }
            for (int i=1;i<n;i++){
                if (!mp[a[n]-i*gcd]){
                    a.push_back(a[n]-i*gcd);
                    break;
                }
            }
            if (int(a.size())==n+1){
                a.push_back(a[n]+gcd);
            }
            sort(a.begin(),a.end());
            vector<LL> pre(n+1,0);
            for (int i=1;i<=n;i++){
                pre[i] = pre[i-1] + (a[n+1]-a[i])/gcd;
            }
            cout << pre[n] << '\n';
        } else{
            cout << 1 << '\n';
        }
    }
}