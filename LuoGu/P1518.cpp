#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
char matrix[12][12];
const i64 dx[] = {0,1,0,-1};
const i64 dy[] = {-1,0,1,0};
i64 cnt,inxf,inyf,inxc,inyc,xc,yc,xf,yf,i,j,d1,d2;
int main(){
    for(i=1;i<=10;i++){
        scanf("%s",matrix[i]+1);
    }
    for(i=0;i<12;i++){
        matrix[i][0] = matrix[i][11] = matrix[0][i] = matrix[11][i] = '*';
    }
    for(i=1;i<=10;i++){
        for(j=1;j<=10;j++){
            if(matrix[i][j] == 'F')inxf = j, inyf = i, xf = j, yf = i;
            if(matrix[i][j] == 'C')inxc = j, inyc = i, xc = j, yc = i;
        }
    }
    // cout << xf << " " << yf << " " << xc << " " << yc << " " << cnt << endl;
    while(1){
        cnt++;
        if(matrix[yf+dy[d1]][xf+dx[d1]] != '*')xf += dx[d1], yf += dy[d1];
        else d1 = (d1+1)%4;
        if(matrix[yc+dy[d2]][xc+dx[d2]] != '*')xc += dx[d2], yc += dy[d2];
        else d2 = (d2+1)%4;
        // cout << xf << " " << yf << " " << xc << " " << yc << " " << cnt << endl;
        if(xf == xc && yf == yc){
            break;
        }
        if(cnt>10000){
            cnt = 0;
            break;
        }
    }
    cout << cnt;
}