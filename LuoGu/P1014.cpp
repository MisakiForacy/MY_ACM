#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n,nn,x=1,y=1,t=1;
    cin >> n;
    nn = n;
    while(nn-t>0){
        nn-=t;
        t++;
    }
    y = t;
    while(--nn){
        x++;
        y--;
    }
    if(t%2)swap(x,y);
    cout << x << "/" << y;
    return 0;
}