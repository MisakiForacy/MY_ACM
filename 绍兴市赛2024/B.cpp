#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    map<char,int> mp;
    string s;
    int n;
    cin >> n;
    cin >> s;
    int mx = 0;
    for (int i=0;i<s.length();i++){
        mp[s[i]] ++;
    }
    int ans = 0;
    for (auto [k,v]:mp){
        ans += v - 1;
    }
    cout << ans << '\n';
}