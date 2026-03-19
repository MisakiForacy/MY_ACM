#include <bits/stdc++.h>
using namespace std;
using LL = long long;
bool ask(int u,int v){
    cout << "? " << u << ' ' << v << '\n';
    int x; cin >> x;
    return x;
}
int main(){
    struct edge{
        int u,v;
    };
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        int cnt = 0;
        vector<edge> ee;
        for (int i=1;i<n;i+=2){
            if (ask(i,i+1)){
                cnt ++;
                ee.push_back({i,i+1});
            }
        }
        if (n&1){
            if (ask(1,n)){
                cnt ++;
                ee.push_back({1,n});
            }
        }
        if (cnt == 0){
            cout << "! 1\n";
        } else{
            int a,b,c,d;
            int ans = 1;
            a = ee[0].u;
            b = ee[0].v;
            for (int i=1;i<=n;i++){
                if (i!=a && i!=b){
                    c = i;
                    break;
                }
            }
            for (int i=1;i<=n;i++){
                if (i!=a && i!=b && i!=c){
                    d = i;
                    break;
                }
            }
            if (ask(a,c)){
                if (ask(a,d)){
                    ans = 2;
                }
            } else if (ask(b,c)){
                if (ask(b,d)){
                    ans = 2;
                }
            }
            cout << "! " << ans << '\n';
        }
    }
}