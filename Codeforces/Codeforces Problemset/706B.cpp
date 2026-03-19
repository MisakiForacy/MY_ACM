#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define debug(x) cerr << #x << ": " << x << '\n'
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll n,p,x;
    cin >> n;
    vector<ll>ar(n);
    for (int i=0;i<n;i++){
        cin >> ar[i];
    }
    sort(ar.begin(),ar.end());
    cin >> p;
    for (int i=0;i<p;i++){
        cin >> x;
        ll idx = upper_bound(all(ar),x)-ar.begin();
        cout << idx << '\n';
    }
}