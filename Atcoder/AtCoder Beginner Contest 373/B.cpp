#include <bits/stdc++.h>
using namespace std;
int main(){
    // string key = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string s;
    cin >> s;
    s = ' ' + s;
    map<char,int> mp;
    int now;
    for (int i=1;i<=26;i++){
        mp[s[i]] = i;
        if (s[i]=='A'){
            now = i;
        }
    }
    int ans = 0;
    for (char c=65;c<91;c++){
        ans += abs(now-mp[c]);
        now = mp[c];
    }
    cout << ans << '\n';
}