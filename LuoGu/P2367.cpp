#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int main(){
    int n,p,mi = inf;
    cin >> n >> p;
    vector<int>a(n+1),b(n+2,0);
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    int x,y,z;
    while (p--){
        cin >> x >> y >> z;
        b[x] += z;
        b[y+1] -= z;
    }
    for (int i=1;i<=n;i++){
        b[i] = b[i] + b[i-1];
        a[i] += b[i];
        mi = min(mi,a[i]);
    }
    cout << mi << '\n';
}