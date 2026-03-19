#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct haha{
    ll w,v,c;
    bool operator < (const haha &that) const {
        if (w*1.0/c != that.w*1.0/that.c) return w*1.0/c > that.w*1.0/that.c;
    }
};
int main(){
    int n;
    cin >> n;
    vector<haha> a(n);
    vector<ll> pre(n+1,0);
    ll sum = 0;
    for (int i=0;i<n;i++){
        cin >> a[i].w >> a[i].v >> a[i].c;
        sum += a[i].v;
    }
    sort(a.begin(),a.end());
    for (int i=0;i<n;i++){
        pre[i+1] = pre[i] + a[i].w;
    }
    for (int i=1;i<=n;i++){
        sum -= a[i-1].c * pre[i-1];
    }
    cout << sum << '\n';
}