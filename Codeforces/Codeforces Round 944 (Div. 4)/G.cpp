#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long i64;
i64 t,n;
vector<i64>ans,a;
void solve();
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}
void solve(){
    cin >> n;
    ans.clear(), ans.resize(n);
    a.clear(), a.resize(n);
    map<i64,vector<i64>>dict;
    for(int i=0;i<n;i++){
        cin >> a[i];
        dict[a[i]>>2].push_back(i);
    }
    for(auto [k,v]:dict){
        vector<i64>b = v;
        sort(v.begin(),v.end(),[&](int i,int j){return a[i]<a[j];});
        for(int i=0;i<v.size();i++){
            ans[b[i]] = a[v[i]];
        }
    }
    for(int i=0;i<n;i++)cout << ans[i] << " ";
    cout << endl;
    return;
}