#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int main(){
    int n,mi = inf;
    cin >> n;
    vector<int>a(n);
    vector<int>pre(n+1,0);
    for (int i=0;i<n;i++){
        cin >> a[i];
        pre[i+1] = pre[i] + a[i];
        mi = min(mi,pre[i+1]);
    }
    if (mi < 0) cout << abs(mi) + 1 << '\n';
    else cout << 1 << '\n';
}