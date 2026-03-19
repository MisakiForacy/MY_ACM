#include <bits/stdc++.h>
using namespace std;
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        string s,t;
        cin >> s >> t;
        int cnt = 0;
        for (int i=0;i<min(s.length(),t.length());i++){
            if (s[i] == t[i]){
                cnt ++;
            } else{
                break;
            }
        }
        if (cnt){
            cout << s.length()-cnt + t.length()-cnt + cnt + 1 << '\n';
        } else{
            cout << s.length() + t.length() << '\n';
        }
    }
}