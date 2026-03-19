#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    map<int,int> mp;
    mp[1] = 10, mp[2] = 20;
    for (auto [k,v]:mp){
        cout << k << ' ' << v << '\n';
    }
}