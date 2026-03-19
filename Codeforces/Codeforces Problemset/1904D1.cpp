#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct haha{
    int x,idx;
    bool operator < (const haha &that) const {
        if (x != that.x){
            return x > that.x;
        }
        return idx < that.idx;
    }
};
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        int ok = 1;
        ll Max = LLONG_MIN;
        vector<ll> a(n+2,0), b(n+2,0);
        priority_queue<haha> Q;
        for (int i=1;i<=n;i++) cin >> a[i];
        for (int i=1;i<=n;i++){
            cin >> b[i];
            if (a[i] > b[i]){
                ok = 0;
            } else if (a[i] != b[i]){
                Q.push({b[i],i});
            }
            Max = max(Max,b[i]);
        }
        a[0] = a[n+1] = b[0] = b[n+1] = Max + 1;
        if (ok){
            while (!Q.empty()){
                auto [x,idx] = Q.top();
                Q.pop();
                int L = 1,R = 1;
                for (int i=idx-1;i>=0;i--){
                    if (x > b[i] || a[i] > x){
                        L = 0;
                        break;
                    } else if (a[i]==x){
                        break;
                    }
                }
                if (!L){
                    for (int i=idx+1;i<=n+1;i++){
                        if (x > b[i] || a[i] > x){
                            R = 0;
                            break;
                        } else if (a[i]==x){
                            break;
                        }
                    }
                }
                if (!L && !R){
                    ok = 0;
                    break;
                }
            }
        }
        cout << (ok?"YES\n":"NO\n");
    }
}