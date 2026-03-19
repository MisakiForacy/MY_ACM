#include <bits/stdc++.h>
#define int long long
using namespace std;
struct haha{
    int id,ss;
};
vector<haha>a;
bool cmp(haha a,haha b){
    return a.ss < b.ss;
}
bool check(vector<int>res,int l,int d){
    sort(res.begin(),res.end());
    if (res[3]-res[0]<=d) return 0;
    int cnt = 0;
    for (int i=0;i<4;i++){
        if (res[i]>=l) cnt++;
    }
    if (cnt >= 2) return 0;
    return 1;
}
void solve(){
    int n,l,d;
    int id,ss;
    cin >> n >> l >> d;
    a.clear();
    for (int i=0;i<n;i++){
        cin >> ss;
        a.push_back({i+1,ss});
    }
    int fi = a[0].ss;
    sort(a.begin(),a.end(),cmp);
    vector<int>res;
    res.push_back(fi);
    if (fi >= l){
        int cnt = 3;
        for (int i=0;i<n;i++){
            if (a[i].id!=1){
                res.push_back(a[i].ss);
                cnt--;
            }
            if (!cnt) break;
        }
    } else{
        int cnt = 2;
        for (int i=0;i<n;i++){
            if (a[i].id!=1){
                res.push_back(a[i].ss);
                cnt--;
            }
            if (!cnt) break;
        }
        if (a[n-1].id==1){
            res.push_back(a[n-2].ss);
        } else{
            res.push_back(a[n-1].ss);
        }
    }
    cout << (check(res,l,d)?"Yes\n":"No\n");
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        solve();
    }
}