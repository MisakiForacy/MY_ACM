#include <bits/stdc++.h>
using namespace std;
using LL = long long;
struct node{
    int x,v;
    bool operator < (const node &that) const {
        return v < that.v;
    }
};
void solve(){
    int n,m,len;
    int l,r;
    cin >> n >> m >> len;
    vector<pair<int,int>> a,b;
    a.push_back({0,0});
    for (int i=0;i<n;i++){
        cin >> l >> r;
        a.push_back({l,r-l+1});
    }
    int x,v,id = 1;
    LL sum, cnt;
    sum = cnt = 0;
    priority_queue<node> Q;
    b.push_back({-1,0});
    for (int i=0;i<m;i++){
        cin >> x >> v;
        b.push_back({x,v});
    }
    b.push_back({len+1,0});
    for (int i=0;i<=m;i++){
        if (b[i].first > a[id-1].first+a[id-1].second)
            Q.push({b[i].first,b[i].second});
        if (id <= n && b[i+1].first > a[id].first){
            while (!Q.empty() && sum < a[id].second){
                sum += Q.top().v;
                Q.pop();
                cnt ++;
            }
            if (sum < a[id].second){
                cout << -1 << '\n';
                return;
            }
            id ++;
        }
    }
    cout << cnt << '\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        solve();
    }
}