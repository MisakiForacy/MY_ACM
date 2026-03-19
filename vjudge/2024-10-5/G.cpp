#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        string s;
        cin >> s;
        int len = s.length();
        s = ' ' + s;
        int L = 0;
        for (int i=1;i<=len;i++){
            if (s[i]=='('){
                L ++;
            } else{    
                L = max(L-1,0);
            }
        }
        if (L > 0){
            cout << "impossible\n";
        } else{
            s.erase(0,1);
            cout << s << '\n'; // hahahahahahaha
        }
    }
}
