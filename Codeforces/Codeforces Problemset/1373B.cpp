#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        string s;
        cin >> s;
        int cnt_1,cnt_0;
        cnt_1 = cnt_0 = 0;
        for (int i=0;i<s.length();i++){
            if (s[i]=='0'){
                cnt_0 ++;
            } else{
                cnt_1 ++;
            }
        }
        cout << (min(cnt_0,cnt_1)&1?"DA\n":"NET\n");
    }
}