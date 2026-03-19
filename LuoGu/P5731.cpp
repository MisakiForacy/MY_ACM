#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define INF 0x3f3f3f3f
#define FOR(i,x,y,z) for(int (i)=(x);(i)!=(y);(i)+=(z))
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    int i=1,n,cc,x=0,y=0,lx=0,rx=0,uy=0,dy=0;
    cin >> n;
    vector<vector<int>>list(n,vector<int>(n));
    if(n%2)cc = n/2+1;
    else cc = n/2;
    for(int c=0;c<cc;c++){
        while(x<=n-rx-1){
            list[y][x] = i;
            x++;
            i++;
        }
        uy++;
        x--;
        y++;
        while(y<=n-dy-1){
            list[y][x] = i;
            y++;
            i++;
        }
        y--;
        rx++;
        x--;
        while(x>=0+lx){
            list[y][x] = i;
            x--;
            i++;
        }
        x++;
        dy++;
        y--;
        while(y>=0+uy){
            list[y][x] = i;
            y--;
            i++;
        }
        y++;
        lx++;
        x++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%3d",list[i][j]);
        }
        cout << endl;
    }
}