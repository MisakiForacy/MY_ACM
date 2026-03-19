#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

using PII = pair<LL, LL>;

void solve() {
    int n;
    cin >> n;
    vector<PII> v(n);
    for(int i = 0;i < n;i ++) cin >> v[i].x >> v[i].y;
    sort(all(v), [&](PII a, PII b){
        if(a.x != b.x) return a.x < b.x;
        return a.y > b.y;
    });
    vector<LL> dp;
    for(auto &p: v){
        LL b = p.y;
        auto it = lower_bound(all(dp), b);
        if(it == dp.end()) dp.push_back(b);
        else *it = b;
    }
    cout << siz(dp) << '\n';
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    while (T --) solve();
}