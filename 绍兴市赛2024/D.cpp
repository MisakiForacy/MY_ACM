#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    LL x;
    cin >> x;
    LL gg = x * 3 - 10;
    LL bb = gg * 3 - 20;
    if (gg > x && bb > gg){
        cout << bb << '\n';
    } else{
        cout << "\"xhx is >_<\"" << '\n';
    }
}