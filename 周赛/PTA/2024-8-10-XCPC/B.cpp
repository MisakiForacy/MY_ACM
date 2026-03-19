#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll pa,pb,pc,pd;
    cin >> pa >> pb >> pc >> pd;
    ll ay=sqrt(pa);
    ll bx,by,cx,cy,dx,dy;
    for(ll i=-sqrt(pc);i<=sqrt(pc);i++){
        ll zj=sqrt(pc-i*i);
        if(i*i+zj*zj==pc){
            cy=i,cx=zj;
            double ex,ey;
            ex=cx/2.0;
            ey=(ay+cy)/2.0;
            dy=ex+ey;
            dx=sqrt(pd-dy*dy);
            bx=dx-(ay-cy);
            by=dy-cx;
            if(cx*cx+(ay-cy)*(ay-cy)==(bx-dx)*(bx-dx)+(by-dy)*(by-dy) && dx*dx+(ay-dy)*(ay-dy)==(bx-cx)*(bx-cx)+(by-cy)*(by-cy)){
                printf("%lld %lld %lld %lld %lld %lld %lld\n",ay,bx,by,cx,cy,dx,dy);
                break;
            }
            //return 0;
        }
    }
}