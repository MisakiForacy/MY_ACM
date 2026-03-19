#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,q,l,r;
    cin >> n;
    vector<int>a(n+1),pre(n+1,0);
    for (int i=1;i<=n;i++){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }
    cin >> q;
    while (q--){
        cin >> l >> r;
        cout << pre[r] - pre[l-1] << '\n';
    }
}