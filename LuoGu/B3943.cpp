#include <iostream>
#include <vector>
typedef long long ll;
typedef double db;
using namespace std;
const db weight[] = {1,1.5,1.5,2,2,2,3,3};
int main(){
    ll x,y,i=1;
    cin >> x >> y;
    for(int i=0;i<=7;i++){
        if(x+12000*weight[i]>=y-12000*weight[i]){cout<<(i+5);return 0;}
    }
    while(x+4*i*12000<y-4*i*12000){
        i++;
    }
    cout << i*13;
    return 0;
}