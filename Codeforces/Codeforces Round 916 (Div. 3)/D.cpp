#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define debug(x) cerr << #x << ':' << x << ' '
using namespace std;
using LL = long long;
const LL inf = LLONG_MAX;

struct node{
    LL x,id;
    bool operator < (const node &that) const {
        return x > that.x;
    }
};

int main(){
    int T = 1;
    cin >> T;
    while (T --){
        int n;
        cin >> n;
        vector<node> a(n), b(n), c(n);       
        for (int i = 0;i < n;i ++) cin >> a[i].x, a[i].id = i;
        for (int i = 0;i < n;i ++) cin >> b[i].x, b[i].id = i;
        for (int i = 0;i < n;i ++) cin >> c[i].x, c[i].id = i;
        sort(all(a)), sort(all(b)), sort(all(c));
        LL ans = 0;
        for (int i = 0;i < 3;i ++){
            for (int j = 0;j < 3;j ++){
                for (int k = 0;k < 3;k ++){
                    if (a[i].id != b[j].id && a[i].id != c[k].id && b[j].id != c[k].id)
                    ans = max(ans, a[i].x + b[j].x + c[k].x);
                }
            }
        }
        cout << ans << '\n';
    }
}