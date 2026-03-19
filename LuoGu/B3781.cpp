#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,x,y,a,b,ss,s,m,aa,bb;
    ll sur=0,mx=0;
    cin >> n >> x >> y >> a >> b;
    aa = bb = 0;
    for (int i=0;i<n;i++){
        cin >> ss >> s >> m;
        int g = m - (ss*x + s*y);
        if (g){
            if (g > ss*x+s*y){
                sur = ceil(sur*1.0 + 1.5*g);
            } else{
                sur += g;
            }
            aa ++;
            bb = 0;
            if (aa>=a){
                sur *= 2;
            }
            mx = max(mx,sur);
        } else{
            aa = 0;
            bb ++;
            if (bb>=b){
                sur /= 2;
            }
        }
    }
    cout << mx << ' ' << sur << '\n';
}