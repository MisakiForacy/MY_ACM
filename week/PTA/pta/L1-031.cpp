#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    double H,W,B;
    cin >> n;;
    while(n--){
        cin >> H >> W;
        W = W/2;
        B = (H - 100) * 0.9;
        if((B-W)>=B * 0.1)cout << "You are tai shou le!" << endl;
        else if((W-B)>=B * 0.1)cout << "You are tai pang le!" << endl;
        else cout << "You are wan mei!" << endl;
    }
}