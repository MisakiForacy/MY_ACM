#include <bits/stdc++.h>
using namespace std;
int a[10];
int main(){
    int y,x=0,n,yy;
    cin >> y >> n;
    memset(a,0,sizeof(a));
    a[y/1000]=1;a[y/100%10]=1;a[y/10%10]=1;a[y%10]=1;
    while(a[0]+a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]!=n){
        x++;
        y++;
        memset(a,0,sizeof(a));
        a[y/1000]=1;a[y/100%10]=1;a[y/10%10]=1;a[y%10]=1;
    }
    cout << x << " " << y/1000 << y/100%10 << y/10%10 << y%10 << endl;
    return 0;
}