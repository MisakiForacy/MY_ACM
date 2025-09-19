#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        string s;
        cin >> s;
        map<char,int> mp;
        for (int i=0;i<s.length();i++){
            mp[s[i]] ++;
        }
        int Max = 0;
        for (auto [k,v]:mp){
            Max = max(v,Max);
        }
        cout << s.length() - Max << '\n';
    }
}