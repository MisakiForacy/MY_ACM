#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n;
    string s,s1 = "sngi", s2 = "ha";
    cin >> n >> s;
    map<char,LL> mp;
    for (int i=0;i<s.length();i++){
        mp[tolower(s[i])] ++;
    }
    LL ans = LLONG_MAX;
    for (int i=0;i<s1.length();i++){
        ans = min(mp[s1[i]],ans);
    }
    for (int i=0;i<s2.length();i++){
        ans = min(mp[s2[i]]/2,ans);
    }
    cout << ans << '\n';
}