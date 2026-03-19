#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    string ans = "";
    map<string,int> mp;
    while (cin >> s){
        if (s=="0") break;
        if (!mp[s]){
            ans.append(s);
            mp[s] ++;
        }
    }
    cout << ans << '\n';
}