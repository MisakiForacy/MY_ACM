#include <iostream>
using namespace std;
const int dd[]={31,28,31,30,31,30,31,31,30,31,30,31};
const int ddd[]={31,29,31,30,31,30,31,31,30,31,30,31};
int main(){
    int y,m;
    bool rn = false;
    cin >> y >> m;
    if(y%4==0){
        if(y%100==0){
            if(y%400==0)rn = true;
        }
        else rn=true;
    }
    if(rn){
        cout << ddd[m-1];
    }else cout << dd[m-1];
    return 0;
}
