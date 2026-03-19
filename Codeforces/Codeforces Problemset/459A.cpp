#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1!=x2&&y1!=y2){
        if (abs(x1-x2)!=abs(y1-y2)){
            cout << -1 << '\n';
        } else{
            ll l = abs(x1-x2);
            if (x2>x1&&y2>y1){
                printf("%d %d %d %d\n",x1,y1+l,x1+l,y1);
            } else if (x2<x1&&y2>y1){
                printf("%d %d %d %d\n",x1,y1+l,x1-l,y1);
            } else if (x2<x1&&y2<y1){
                printf("%d %d %d %d\n",x1,y1-l,x1-l,y1);
            } else{
                printf("%d %d %d %d\n",x1,y1-l,x1+l,y1);
            }
        }
    } else{
        ll l = max(abs(y2-y1),abs(x2-x1));
        if (x2==x1){
            printf("%d %d %d %d\n",x1+l,y1,x2+l,y2);
        } else if (y2==y1){
            printf("%d %d %d %d\n",x1,y1+l,x2,y2+l);
        }
    }
}