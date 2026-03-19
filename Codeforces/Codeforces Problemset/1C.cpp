#include <bits/stdc++.h>
#define EPS 1e-2
using namespace std;
typedef long double llf;
const llf PI = acos(-1.0);
llf ax,ay,bx,by,cx,cy;
llf a,b,c,p,S,r;
llf theta1,theta2,theta3,theta;
llf ans;
double fgcd(llf a,llf b){
    if (fabs(b) < EPS) return a;
    if (fabs(a) < EPS) return b;
    return fgcd(b,fmod(a,b));
}
void solve(){
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    a = sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
    b = sqrt((bx-cx)*(bx-cx)+(by-cy)*(by-cy));
    c = sqrt((cx-ax)*(cx-ax)+(cy-ay)*(cy-ay));
    p = (a+b+c) / 2;
    S = sqrt(p*(p-a)*(p-b)*(p-c));
    r = (a*b*c) / (4*S);
    theta1 = acos(1-(a*a)/(2*r*r));
    theta2 = acos(1-(b*b)/(2*r*r));
    theta3 = 2*PI - theta1 - theta2;
    theta = fgcd(theta1,fgcd(theta2,theta3));
    ans = PI*r*r*sin(theta)/theta;
    cout << fixed << setprecision(8) << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}