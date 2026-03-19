#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(ll a,ll b){
    return a > b;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n,k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i=0;i<n;i++) cin >> a[i];
        sort(a.begin(),a.end(),cmp);
        ll tot = 0;
        for (int i=1;i<n;i+=2){
            tot += a[i-1] - a[i];
        }
        tot = max(0LL,tot - k);
        if (n&1) tot += a.back();
        cout << tot << '\n';
    }
}
