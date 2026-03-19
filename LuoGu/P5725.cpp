#include <iostream>
#include <vector>
#include <algorithm>
#define INF 0x3f3f3f3f
#define N 100000
#define FOR(i,x,y,z) for(int (i)=(x);(i)!=(y);(i)+=(z))
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    int n,num=1;
    cin >> n;
    FOR(i,0,n,1){
        FOR(j,0,n,1){
            cout << num/10 << num%10;
            num++;
        }db
        cout << endl;
    }
    cout << endl;
    num = 1;
    FOR(i,0,n,1){
        FOR(k,0,(n-i-1)*2,1){
            cout << " ";
        }
        FOR(j,0,i+1,1){
            cout << num/10 << num%10;
            num++;
        }
        cout << endl;
    }
    return 0;
}