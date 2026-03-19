#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        string s,t;
        cin >> s >> t;
        int p1 = 0,p2;
        int ls = s.length();
        int lt = t.length();
        int ok = 1;
        vector<char>ans(ls);
        for (int i=0;i<ls;i++){
            ans[i] = s[i];
        }
        for (p2=0;p2<lt;p2++){
            while (p1!=ls && (s[p1]!='?' && s[p1]!=t[p2])) p1 ++;
            // cout << p1 << '\n';
            if (p1==ls){
                ok = 0;
                break;
            }
            if (s[p1]=='?'||t[p2]==s[p1]){
                if (s[p1]=='?'){
                    ans[p1] = t[p2];
                }
                p1 ++;
            }
        }
        if (ok){
            cout << "YES\n";
            for (int i=0;i<ls;i++){
                if (ans[i]=='?'){
                    ans[i] = 'a';
                }
            }
            for (int i=0;i<ls;i++){
                cout << ans[i];
            }
            cout << '\n';
        } else{
            cout << "NO\n";
        }
    }
}