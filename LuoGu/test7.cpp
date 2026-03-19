#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,x,y,z) for(int (i)=(x);(i)!=(y);(i)+=(z))
using namespace std;
typedef long long ll;
int f[20][20];
int main(){
    int n;
    cin >> n;
    FOR(i,0,n+1,1){
        f[i][0] = 1;
    }
    FOR(j,1,n+1,1){
        FOR(i,0,n+1,1){
            if(i>=1)f[i][j] = f[i-1][j] + f[i+1][j-1];
            if(i==0)f[i][j] = f[i+1][j-1];
        }
    }
    cout << f[0][n];
}
