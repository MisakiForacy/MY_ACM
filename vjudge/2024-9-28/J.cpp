#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int x,n,W;
    cin >> n >> W;
    map<int,int> mp;
    for (int i=0;i<n;i++){
        cin >> x;
        mp[x] ++;
    }
    vector<int> m;
    for (auto [k,v]:mp){
        m.push_back(v);
    }
    int n
}