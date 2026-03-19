#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        string s;
        cin >> s;
        map<char,int>mp;
        for (int i=0;i<8;i++){
            mp[s[i]]++;
        }
        if (s[0]!=s[4]){
            if (mp[s[0]]>mp[s[4]]){
                cout << s[0] << '\n';
            } else if (mp[s[0]]<mp[s[4]]){
                cout << s[4] << '\n';
            } else{
                cout << 'N' << '\n';
            }
        } else{
            cout << s[0] << '\n';
        }
    }
}