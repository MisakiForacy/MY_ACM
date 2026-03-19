#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <iomanip>
#define N 100000
#define INF 0x3f3f3f3f
#define PI 3.141592
#define e 2.718281
#define FOR(i,x,y,z) for(int (i)=(x);(i)!=(y);(i)+=(z))
#define elif else if
typedef long long ll;
typedef double db;
using namespace std;
const char num[] = {0,1,2,3,4,5,6,7,8,9};
int main(){
    int n,nn=1;
    cin >> n;
    FOR(i,0,n,1){
        FOR(j,0,n-i,1){
            cout << nn/10 << nn%10;
            nn++;
        }
        cout << endl;
    }
    return 0;
}