#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct haha{
    int x,y;
};
int main(){
    int n,k,b,x,y;
    cin >> n >> k >> b;
    vector<int> up,down,mid;
    vector<int> vis(2*n+1,0);
    for (int i=1;i<=2*n;i++){
        cin >> x >> y;
        if (k*x+b>y || (y-b)/k<x){
            down.push_back(i);
        } else if (k*x+b>y || (y-b)/k>x){
            up.push_back(i);
        } else{
            mid.push_back(i);
        }
    }
    int u,d,m;
    u = up.size(), d = down.size(), m = mid.size();
    int mm = m;
    if (u > d){
        if (u - d >= m){
            for (int i=0;i<m;i++){
                down.push_back(mid[i]);
            }
            m = 0, d += m;
        } else{
            for (int i=0;i<u-d;i++){
                down.push_back(mid[i]);
            }
            m -= u-d, d = u;
        }
    } else if (u < d){
        if (d - u >= m){
            for (int i=0;i<m;i++){
                up.push_back(mid[i]);
            }
            m = 0, u += m;
        } else{
            for (int i=0;i<d-u;i++){
                up.push_back(mid[i]);
            }
            m -= d-u, u = d;
        }
    }
    if (m){
        int idx = mm - m;
        for (int i=idx;i<idx+m/2;i++){
            up.push_back(mid[i]);
        }
        for (int i=idx+m/2;i<mm;i++){
            down.push_back(mid[i]);
        }
    }
    u = up.size(), d = down.size();
    int ans = min(u, d);
    cout << ans << '\n';
    for (int i=0;i<ans;i++){
        for (int j=0;j<ans;j++){
            cout << up[i] << ' ' << down[j] << " Y\n";
        }
    }
    if (ans==up.size()){
        for (int i=ans;i<down.size();i+=2){
            cout << down[i] << ' ' << down[i+1] << " N\n";
        }
    } else{
        for (int i=ans;i<up.size();i+=2){
            cout << up[i] << ' ' << up[i+1] << " N\n";
        }
    }
}