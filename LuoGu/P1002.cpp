#include <iostream>
#include <vector>
#define FOR(i,x,y,z) for(int (i)=(x);(i)!=(y);(i)+=(z))
typedef long long ll;
using namespace std;
const int dx[] = {0,-1,1,2,2,1,-1,-2,-2};
const int dy[] = {0,-2,-2,-1,1,2,2,1,-1};
int main(){
    vector<vector<ll>>map(30,vector<ll>(30,0));
    vector<vector<bool>>ss(30,vector<bool>(30,0));
    ll bx,by,hx,hy;
    cin >> bx >> by >> hx >> hy;
    bx+=2;by+=2;hx+=2;hy+=2;
    map[2][1] = 1;
    FOR(i,0,9,1)ss[hy+dy[i]][hx+dx[i]]=1;
    FOR(i,2,by+1,1){
        FOR(j,2,bx+1,1){
            if(ss[i][j])continue;
            map[i][j] = map[i-1][j] + map[i][j-1];
        }
    }
    cout << map[by][bx];
    return 0;
}