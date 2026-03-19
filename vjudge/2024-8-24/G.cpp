#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int h,w;
        cin >> h >> w;
        h = (h-100)*1.8;
        if (fabs(h-w)<h*0.1){
            cout << "You are wan mei!\n";
        } else if (w > h){
            cout << "You are tai pang le!\n";
        } else{
            cout << "You are tai shou le!\n";
        }
    }
}