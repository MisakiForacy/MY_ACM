#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using LL = long long;
double d(double ax,double ay,double bx,double by){
    return sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
}
struct node{
    double idx,sx,sy,fx,fy;
    bool operator < (const node&that) const {
        return idx < that.idx;
    }
};
int main(){
    double n,s,t;
    cin >> n >> s >> t;
    double ans = 0;
    double ax,ay,bx,by;
    vector<node> l;
    for (int i=0;i<n;i++){
        cin >> ax >> ay >> bx >> by;
        l.push_back({i,ax,ay,bx,by});
        ans += d(ax,ay,bx,by);
    }
    sort(l.begin(),l.end());
    ans /= t;
    double sx,sy;
    sx = sy = 0;
    double Min = LLONG_MAX;
    do{
        sx = sy = 0;
        for (int i=0;i<(1<<(int)n);i++){
            double w = 0;
            sx = sy = 0;
            for (int j=0;j<n;j++){
                if ((i >> j)&1){
                    w += d(sx,sy,l[j].sx,l[j].sy);
                    sx = l[j].fx, sy = l[j].fy;
                } else{
                    w += d(sx,sy,l[j].fx,l[j].fy);
                    sx = l[j].sx, sy = l[j].sy;
                }
            }
            Min = min(Min,w);
            // cout << Min << '\n';
        }
    } while (next_permutation(l.begin(),l.end()));
    cout << fixed << setprecision(6) << ans + Min / s << '\n';
    // cout << ans << '\n';
}