#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define N 100000
#define INF 0x3f3f3f3f
#define FOR(i,x,y,z) for(int (i)=(x);(i)!=(y);(i)+=(z))
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    ll n,k,nn,num,sum = 0,total = 0,MAXN = 1;
    cin >> n >> k;
    MAXN = pow(10,n);
    FOR(i,1,MAXN,1){
        nn = n;
        sum = 0;
        num = i;
        while(nn--){
            sum += num % 10;
            num /= 10;
        }
        if(sum <= k)total+=1;
    }
    cout << total;
    return 0;
}