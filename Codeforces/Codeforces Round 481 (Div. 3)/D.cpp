#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
using LL = long long;
int main(){
    int n;
    cin >> n;
    vector<LL> a(n);
    for (int i = 0;i < n;i ++) cin >> a[i];
    // sort(all(a));
    LL mx = 0, mi = 0;
    if (a.size() > 1){
        mx = a[1] - a[0] + 2;
        mi = a[1] - a[0] - 2;
    }
    LL ans = 1e12;
    for (LL d = mi;d <= mx;d ++){
        LL x,y,z;
        x = z = y = 0;
        LL n1 = a[0] - 1, n2 = a[0], n3 = a[0] + 1;
        for (int i = 0;i < n;i ++){
            if (abs(n1 - a[i]) > 1) x = 1e12;
            else if (abs(n1 - a[i]) == 1 && x != 1e12) x ++;
            if (abs(n2 - a[i]) > 1) y = 1e12;
            else if (abs(n2 - a[i]) == 1 && y != 1e12) y ++;
            if (abs(n3 - a[i]) > 1) z = 1e12;
            else if (abs(n3 - a[i]) == 1 && z != 1e12) z ++;
            n1 += d, n2 += d, n3 += d;
        }
        ans = min({ans,x,y,z});
    }
    cout << (ans >= 1e12 ? -1 : ans) << '\n';
}