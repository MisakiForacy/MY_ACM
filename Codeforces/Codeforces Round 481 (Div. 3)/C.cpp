#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
using LL = long long;
int main(){
    int n,m;
    cin >> n >> m;
    vector<LL> a(n + 1, 0);
    for (int i = 1;i <= n;i ++){
        cin >> a[i];
        a[i] += a[i - 1];
    }
    LL q;
    while (m --){
        cin >> q;
        cout << lower_bound(all(a),q) - a.begin() << ' ' << q - *(lower_bound(all(a),q)-1) << '\n';
    }
}