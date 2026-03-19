#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f;
struct haha{
    vector<int>a;
};
int main(){
    int n,m,k,t;
    cin >> n >> m >> k >> t;
    vector<vector<haha>> mp(n,vector<haha>(m));
    for (int i=0;i<t;i++){
        int a,x,y;
        cin >> a >> x >> y;
        x --,y--;
        if (mp[x][y].a.size()==k){
            ll mi = inf;
            ll nu,idx;
            for (int i=0;i<k;i++){
                if (mp[x][y].a[i] < mi){
                    mi = mp[x][y].a[i];
                    nu = k - i - 1;
                    idx = i;
                }
            }
            cout << mi << ' ' << nu << '\n';
            mp[x][y].a.erase(mp[x][y].a.begin()+idx);
            mp[x][y].a.push_back(a);
        } else{
            cout << -1 << '\n';
            mp[x][y].a.push_back(a);
        }
    }
}