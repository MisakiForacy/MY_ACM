#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#define FOR(i,x,y,z) for(int (i)=(x);(i)!=(y);(i)+=(z))
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
vector<vector<int>> f(20,vector<int>(20,0));
int main(){
    int n;
    cin >> n;
    FOR(i,0,n+1,1){
        f[i][0] = 1;
    }
    FOR(j,1,n+1,1){
        FOR(i,0,n+1,1){
            if(i>=1) f[i][j] = f[i-1][j] + f[i+1][j-1];
            else f[i][j] = f[i+1][j-1];
        }
    }
    cout << f[0][n] << endl;
    FOR(i,0,n,1){
        for(vector<int>::iterator it=f[i].begin();it!=f[i].end();it++){
            printf("%-3d",*it);
        }
        cout << endl;
    }
    return 0;
}