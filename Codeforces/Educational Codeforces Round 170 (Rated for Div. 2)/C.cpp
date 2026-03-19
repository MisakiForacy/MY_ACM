#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,k;
        cin >> n >> k;
        vector<LL> a(n);
        map<LL,LL> mp;
        for (int i=0;i<n;i++){
            cin >> a[i];
            mp[a[i]] ++;
        }
        vector<pair<LL,LL>> b;
        for (auto [x,v]:mp){
            b.push_back({x,v});
        }
        LL ans,Max;
        ans = b[0].second;
        queue<LL> Q;
        Max = ans;
        Q.push(b[0].second);
        for (int i=1;i<b.size();i++){
            if (Q.size()<k){
                if (b[i].first==b[i-1].first+1){
                    Q.push(b[i].second);
                    ans += b[i].second;
                } else{
                    while (Q.size()) Q.pop();
                    ans = b[i].second;
                    Q.push(b[i].second);
                }
            } else{
                if (b[i].first==b[i-1].first+1){
                    Q.push(b[i].second);
                    ans += b[i].second;
                    ans -= Q.front();
                    Q.pop();
                } else{
                    while (Q.size()) Q.pop();
                    ans = b[i].second;
                    Q.push(b[i].second);
                }
            }
            Max = max(Max,ans);
        }
        cout << Max << '\n';
    }
}