#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n;
    int x;
    cin >> n;
    LL tot = 0;
    for (int i=0;i<n;i++){
        cin >> x;
        tot = tot + (1LL<<i)*x;
        if (tot == 0){
            cout << 0;
        } else{
            cout << (tot>0?'+':'-');
        }
    }
}