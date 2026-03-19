#include <bits/stdc++.h>
using namespace std;
int main(){
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    string s;
    map<string,int>mp;
    while (cin >> s){
        string ns = "";
        for (int i=0;i<s.length();i++){
            if (isalpha(s[i])){
                ns.push_back(tolower(s[i]));
            } else{
                mp[ns]++;
                ns = "";
            }
        }
        mp[ns]++;
    }
    for (auto c:mp){
        if (isalpha(c.first[0]))cout << c.first << '\n';
    }
}