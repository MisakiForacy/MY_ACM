#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x,mx=0;
    cin >> n;
    map<int,int>mp;
    for (int i=0;i<n;i++){
        cin >> x;
        mp[x-1]++;
        mp[x+1]++;
        mp[x]++;
    }
    for (auto c:mp){
        mx = max(mx,c.second);
    }
    cout << mx << '\n';
}