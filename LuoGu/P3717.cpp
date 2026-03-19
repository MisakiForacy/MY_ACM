#include <bits/stdc++.h>
#define N 105
using namespace std;
int n,m,r,i,j,t,y,x,cnt;
int matrix[N][N];
int main(){
    cin >> n >> m >> r;
    while(m--){
        cin >> x >> y;
        for(i=(y-r<1?1:y-r);i<=(y+r>n?n:y+r);i++){
            for(j=(x-r<1?1:x-r);j<=(x+r>n?n:x+r);j++){
                if(sqrt((y-i)*(y-i)+(x-j)*(x-j))<=r)matrix[i][j] = 1;
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cnt += matrix[i][j];
        }
    }
    cout << cnt << endl;
    return 0;
}