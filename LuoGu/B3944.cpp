#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
#define N 100000
#define Mod 722733748
#define FOR(i,x,y,z) for(int (i)=(x);(i)!=(y);(i)+=(z))
using namespace std;
typedef long long ll;
typedef double db;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll k,a,q,total;
    cin >> k >> a >> q;total = a;
    FOR(kk,1,k,1){
        a = (a * q) % Mod;
        total = (total * a) % Mod;
    }
    cout << total % Mod;
    return 0;
}