#include <bits/stdc++.h>
using namespace std;
int main(){
    double x1,y1,r1,x2,y2,r2,d;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    d = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)) - r1 - r2;
    if (d <= 0){
        printf("%.2lf",0);
    } else{
        printf("%.2lf",d);
    }
}