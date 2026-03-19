#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#define INF 0x3f3f3f3f
#define FOR(i,x,y,z) for(int (i)=(x);(i)!=(y);(i)+=(z))
using namespace std;
typedef long long ll;
typedef double db;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N,M,K,total=0;
    cin >> N >> M >> K;
    vector<ll>list;
    FOR(i,1,min(K+1,N+1),1){
        FOR(j,1,min(K+1,M+1),1){
            if(i*j/__gcd(i,j)<=K)
                list.push_back(i*j/__gcd(i,j));
                
        }
    }
    FOR(k,1,K+1,1){
        for(vector<ll>::iterator it=list.begin();it!=list.end();it++){
            if(k%*it==0)total+=k;
        }
    }
    cout << total;
}