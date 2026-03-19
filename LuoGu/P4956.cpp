#include <iostream>
using namespace std;
int main(){
    int n,x,k;
    cin >> n;
    for(x=100;x>=1;x--){
        for(k=1;k<=200;k++){
            if(n/52-21*k-7*x==0){
                printf("%d\n%d",x,k);
                return 0;
            }
        }
    }
}