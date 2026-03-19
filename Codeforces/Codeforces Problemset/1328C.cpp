#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,f=0;
        cin >> n;
        string s,a,b;
        cin >> s;
        a = b = "";
        for (int i=0;i<n;i++){
            if (s[i]=='1'){
                a.push_back('1');
                b.push_back('0');
                f = i+1;
                break;
            } else{
                if (s[i]=='0'){
                    a.push_back('0');
                    b.push_back('0');
                } else{
                    a.push_back('1');
                    b.push_back('1');
                }
            }
        }
        if (f){
            for (int i=f;i<n;i++){
                a.push_back('0');
                b.push_back(s[i]);
            }
        }
        cout << a << '\n' << b << '\n';
    }
}