#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (s[0]==s.back()){
            cout << "NO\n";
        } else{
            cout << "YES\n";
        }
    }
}