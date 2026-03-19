#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,z = 0;
        cin >> n;
        string s;
        cin >> s;
        for (int i=0;i<n;i++){
            if (s[i]=='0') z ++;
        }
        if (z&1 && ((z/2)&1)){
            cout << "ALICE\n";
        } else{
            cout << "BOB\n";
        }
    }
}