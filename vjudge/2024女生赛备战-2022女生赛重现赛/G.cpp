#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 5e5+10;
int ti[N],xi[N],res[N];
int main(){
    int t,n,m,k;
    cin >> t >> n >> m >> k;
    for (int i=1;i<=m;i++){
        cin >> ti[i] >> xi[i];
        res[i] = max(0,res[i-1]-k*(ti[i]-ti[i-1]))+xi[i];
    }
    int id = lower_bound(ti,ti+m+1,t)-ti-1;
    int ok = 1;
    if (max(0,res[id]-k*(t-ti[id])) != n){
        ok = 0;
    }
    // for (int i=1;i<=m;i++){
    //     cout << res[i] << '\n';
    // }
    if (ok){
        // cout << '\n';
        int ans = INT_MAX;
        if (ti[id] != t) id ++;
        int idx;
        for (int i=id;i<=m;i++){
            // cout << (res[i]+1)/k << '\n';
            if (ans >= ((res[i]+1)/k+((res[i]+1)%k?1:0))){
                ans = ((res[i]+1)/k+((res[i]+1)%k?1:0));
                idx = ti[i];
            }
            // cout << i << ' ' << ans << '\n';
        }
        // cout << ans << '\n';
        cout << idx << ' ' << ans << '\n';
    } else{
        cout << "Wrong Record\n";
    }
}