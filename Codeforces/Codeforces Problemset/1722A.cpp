#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        string s;
        cin >> n;
        cin >> s;
        if (n != 5){
            cout << "NO\n";
        } else{
            map<char,int>mp;
            for (int i=0;i<n;i++){
                mp[s[i]] ++;
            }
            if (mp['T']!=1||mp['i']!=1||mp['m']!=1||mp['u']!=1||mp['r']!=1){
                cout << "NO\n";
            } else{
                cout << "YES\n";
            }
        }
    }
}