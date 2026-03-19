#include <iostream>
#include <cstring>
typedef long long ll;
using namespace std;
const int dy[] = {0,-2,-2,-1,1,2,2,1,-1};
const int dx[] = {0,-1,1,2,2,1,-1,-2,-2};
int main(){
    int bx,by,hx,hy;
    ll map[40][40],ss[40][40];
    cin >> bx >> by >> hx >> hy;
    bx+=2;by+=2;hx+=2;hy+=2;
    memset(map,0,sizeof(map));
    memset(ss,0,sizeof(ss));
    for(int i=0;i<9;i++){
        ss[hy+dy[i]][hx+dx[i]] = 1;
    }
    for(int i=2;i<=by;i++){
        for(int j=2;j<=bx;j++){
            if(!ss[i][j])map[i][j] = map[i-1][j] + map[i][j-1];
        }
    }
    cout << map[by-1][bx-1];
    return 0;
}
