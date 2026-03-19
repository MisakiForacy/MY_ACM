#include <bits/stdc++.h>
#define PI 3.1415926535897932384626433832
#define EPS 1e-2
typedef long double llf;
using namespace std;
bool flg = true;
llf ax,ay,bx,by,cx,cy;
llf dx,dy,ex,ey,fx,fy,ox,oy;
llf l1,l2,l3,l4,l5,l6,r;
llf l1_k,l2_k,l3_k,l4_k,l5_k,l6_k;
llf l1_d,l2_d,l3_d,l4_d,l5_d,l6_d;
llf theta1,theta2,theta3,theta;
llf gcd,l,ans;
llf S,p;
double fgcd(double a,double b){
    if (fabs(b) < EPS) return a;
    if (fabs(a) < EPS) return b;
    return fgcd(b,fmod(a,b));
}
void solve(){
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    dx = (ax+bx) / 2; dy = (ay+by) / 2;
    ex = (bx+cx) / 2; ey = (by+cy) / 2;
    fx = (ax+cx) / 2; fy = (ay+cy) / 2;
    if (by-ay) {
        l4_k = (ax-bx) / (by-ay), l4_d = dy - dx*l4_k;
    } else {
        ox = (ax+bx) / 2, flg = false;
    } if (cy-by){
        l5_k = (bx-cx) / (cy-by), l5_d = ey - ex*l5_k;
    } else {
        ox = (bx+cx) / 2, flg = false;
    } if (cy-ay) {
        l6_k = (ax-cx) / (cy-ay), l6_d = fy - fx*l6_k;
    } else {
        ox = (ax+cx) / 2, flg = false;
    } if (flg) ox = (l5_d-l4_d) / (l4_k-l5_k);
    oy = max(ox*l4_k + l4_d,ox*l5_k + l5_d);
    // cout << (oy == (ox*l5_k + l5_d)) << '\n';
    // cout << ox << " " << oy << '\n';
    l1 = sqrt((bx-ax)*(bx-ax)+(by-ay)*(by-ay));
    l2 = sqrt((cx-bx)*(cx-bx)+(cy-by)*(cy-by));
    l3 = sqrt((ax-cx)*(ax-cx)+(ay-cy)*(ay-cy));
    l4 = sqrt((ox-dx)*(ox-dx)+(oy-dy)*(oy-dy));
    l5 = sqrt((ox-ex)*(ox-ex)+(oy-ey)*(oy-ey));
    l6 = sqrt((ox-fx)*(ox-fx)+(oy-fy)*(oy-fy));
    r = sqrt((ox-ax)*(ox-ax)+(oy-ay)*(oy-ay));

    p = (l1+l2+l3) / 2;
    S = sqrt(p*(p-l1)*(p-l2)*(p-l3));
    r = (l1*l2*l3) / (4*S);
    // cout << r << '\n';
    // cout << (sqrt((ox-bx)*(ox-bx)+(oy-by)*(oy-by))) << '\n';
    // cout << (sqrt((ox-cx)*(ox-cx)+(oy-cy)*(oy-cy))) << '\n';
    // cout << l1 << " " << l2 << " " << l3 << " " << l4 << " " << l5 << " " << l6 << " " << r << '\n';
    // cout << (l3*l6) / (r*r) << '\n';
    theta1 = asin((l1*l4)/(r*r)>=1?1:(l1*l4)/(r*r)<=-1?-1:(l1*l4)/(r*r));
    theta2 = asin((l2*l5)/(r*r)>=1?1:(l2*l5)/(r*r)<=-1?-1:(l2*l5)/(r*r));
    theta3 = asin((l3*l6)/(r*r)>=1?1:(l3*l6)/(r*r)<=-1?-1:(l3*l6)/(r*r));
    // theta1 = (theta1?theta1:180);
    // theta2 = (theta2?theta2:180);
    // theta3 = (theta3?theta3:180);

    // cout << asin(1.0)/PI*180 << '\n';
    // gcd = min(__gcd((int)theta1,(int)theta2),min(__gcd((int)theta1,(int)theta3),__gcd((int)theta2,(int)theta3)));
    gcd = fgcd(theta1,fgcd(theta2,theta3)) / 2;
    cout << gcd << '\n';

    // theta = gcd*PI/180;
    l = r * sin(gcd);
    cout << l << '\n';
    cout << PI/gcd << '\n';
    cout << r << '\n';
    ans = sqrt(r*r-l*l)*l*(PI/gcd);
    cout << fixed << setprecision(8) << ans << '\n';
    // cout << theta1 << '\n';
    // cout << theta2 << '\n';
    // cout << theta3 << '\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}