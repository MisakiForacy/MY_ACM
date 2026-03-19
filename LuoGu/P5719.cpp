#include <iostream>
#include <iomanip>
typedef double db;
using namespace std;
int main(){
    db n,k,A=0,B=0,num_A;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        if(i%int(k))B+=i;
        else A+=i,num_A++;
    }
    cout<<fixed<<setprecision(1)<<A/num_A<<" "<<B/(n-num_A);
    return 0;
}