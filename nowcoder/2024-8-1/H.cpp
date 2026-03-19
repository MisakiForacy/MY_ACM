#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        string s;
        cin >> s;
        int len = s.length();
        int cnt3 = 0, cnt5 = 0, ok = 1;
        vector<int>idx;
        for (int i=0;i<len;i++){
            if (s[i]=='3'){
                cnt3 ++;
            } else{
                cnt3 = 0;
            }
            if (s[i]=='5') idx.push_back(i);
            if (s[i]!='5'&&s[i]!='U'){
                cnt5 ++;
            } else{
                cnt5 = 0;
            }
            if (cnt3 >= 10){
                // cout << 3 << ' ' << cnt3 << '\n';
                ok = 0;
            }
            if (cnt5 >= 90){
                // cout << 5 << ' ' << cnt5 << '\n';
                ok = 0;
            }
        }
        for (int i=1;i<idx.size();i++){
            int f = 1;
            for (int j=idx[i-1]+1;j<idx[i];j++){
                if (s[j]=='U'){
                    f = 0;
                    break;
                }
            }
            if (f) ok = 0;
        }
        cout << (ok?"valid\n":"invalid\n");
    }
}