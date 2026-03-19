#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,m,t,l,r;
    cin >> n;
    vector<ll>a(n+1,0), a_prefix(n+1,0);
    vector<ll>b(n+1,0), b_prefix(n+1,0);
    for (int i=1;i<=n;i++){
        cin >> a[i];
        b[i] = a[i];
        a_prefix[i] = a_prefix[i-1]+a[i];
    }
    sort(b.begin()+1,b.end());
    for (int i=1;i<=n;i++){
        b_prefix[i] = b_prefix[i-1]+b[i];
    }
    cin >> m;
    while (m--){
        cin >> t >> l >> r;
        if (t==1){
            cout << a_prefix[r]-a_prefix[l-1] << '\n';
        } else{
            cout << b_prefix[r]-b_prefix[l-1] << '\n';
        }
    }
}