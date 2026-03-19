#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int f(char c){
    if (c == '(' || c == ')') return 2;
    if (c == '[' || c == ']') return 1;
    return 0;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        string s;
        cin >> s;
        int id = 0,len,ok = 1,cnt = 0;
        for (int i=1;i<s.length();i++){
            if (f(s[i]) == f(s[i-1])){
                cnt ++;
                len = i - id;
                int l = id, r = i + len - 1;
                while (l < r){
                    if (f(s[l]) != f(s[r])){
                        ok = 0;
                    }
                    l ++, r --;
                    if (l < r && f(s[l]) == f(s[l-1])){
                        ok = 0;
                    }
                }
                id = i + len;
                i = id;
                if (f(s[id]) == f(s[id-1])){
                    ok = 0;
                }
            }
        }
        if (cnt > 2){
            ok = 0;
        }
        cout << (ok?"Yes\n":"No\n");
    }
}