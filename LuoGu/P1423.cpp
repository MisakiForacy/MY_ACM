#include <iostream>
using namespace std;
int main(){
    double s,init=2,step=1;
    cin >> s;
    while(s-init>0){
        s-=init;
        init*=0.98;
        step++;
    }
    cout << step;
}