#include <bits/stdc++.h>
#define endl '\n'
#define N (i64)(2e5+10)
using namespace std;
typedef long long i64;
typedef double llf;
i64 t,n,k,q,d,r;
vector<i64>ans;
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
    ans.clear();
    cin >> n >> k >> q;
    vector<i64>a(k+1), b(k+1);
    a[0] = 0, b[0] = 0;
    for(int i = 1; i <= k; i ++)cin >> a[i];
    for(int i = 1; i <= k; i ++)cin >> b[i];
    for(int i = 0; i < q; i ++){
        cin >> d;
        r = upper_bound(a.begin(),a.end(),d) - a.begin();
        llf dd = a[r] - a[r-1];
        llf dt = b[r] - b[r-1];
        llf dg = d - a[r-1];
        ans.push_back((i64)(dg*dt/dd+b[r-1]));
    }
    for(vector<i64>::iterator it = ans.begin(); it != ans.end(); it ++){
        cout << *it << " ";
    }
    cout << endl;
}