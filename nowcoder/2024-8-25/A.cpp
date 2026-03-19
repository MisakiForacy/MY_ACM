#include <bits/stdc++.h>
using namespace std;
int main(){
    int x,idx;
    for (int i=1;i<=5;i++){
        cin >> x;
        if (x==1){
            idx = i;
        }
    }
    cout << idx << '\n';
}