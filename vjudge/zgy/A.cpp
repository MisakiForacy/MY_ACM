#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
using LL = long long;
int main(){
    int n;
    cin >> n;
    vector<pair<LL,LL>> a(n);
    for (int i=0;i<n;i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(all(a),[&](pair<LL,LL> x,pair<LL,LL> y){
        return x.first < y.first;
    });
    LL ans = 0;
    priority_queue<LL,vector<LL>,greater<>> Q;
    for (int i=0;i<n;i++){
        if (a[i].first > Q.size()){
            ans += a[i].second;
            Q.push(a[i].second);
        } else if (Q.size() && a[i].second > Q.top()){
            ans = ans - Q.top() + a[i].second;
            Q.pop(), Q.push(a[i].second);
        }
    }
    cout << ans << '\n';
}