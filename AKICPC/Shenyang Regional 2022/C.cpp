#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL f(LL l,LL r,LL x){
    if (x < l) return l;
    if (x > r) return r;
    return x;
}
int main(){
    LL n,d;
    cin >> n >> d;
    vector<LL> a(n);
    set<LL> st;
    for (int i=0;i<n;i++){
        cin >> a[i];
        st.insert(a[i]);
    }
    LL ans = 0;
    for (auto x:st){
        LL l = x, r = x + d;
        LL sum = 0;
        for (int i=1;i<n;i++){
            sum += labs(f(l,r,a[i-1])-f(l,r,a[i]));
        }
        ans = max(ans,sum);
        l = x - d, r = x, sum = 0;
        for (int i=1;i<n;i++){
            sum += labs(f(l,r,a[i-1])-f(l,r,a[i]));
        }
        ans = max(ans,sum);
    }
    cout << ans << '\n';
}