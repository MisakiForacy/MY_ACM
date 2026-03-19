#include <iostream>
#define N 2000001
using namespace std;
typedef long long ll;
typedef double db;
ll light[N];
int main(){
    int n;
    db a,t;
    cin >> n;
    for(int j=0;j<n;j++){
        cin >> a >> t;
        for(ll i=1;i<=t;i++){
            light[int(a*i)] = light[int(a*i)] ^ 1;
        }
    }
    ll i=0;
    while(light[i]!=1){
        ++i;
    }
    cout << i;
}