// #include <bits/stdc++.h>
#include <iostream>
#define N 250
using namespace std;
int m[N][N];
int i,j,k,n,x,y;
int x1,y1,x2,y2,cnt;
int main(){
    cin >> x >> y >> k;
    for(n=0;n<k;n++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(i=y1;i<=y2;i++){
            for(j=x1;j<=x2;j++){
                m[i][j] = 1;
            }
        }
    }
    for(i=1;i<=y;i++){
        for(j=1;j<=x;j++){
            cnt += m[i][j];
        }
    }
    cout << cnt << endl;
    return 0;
}