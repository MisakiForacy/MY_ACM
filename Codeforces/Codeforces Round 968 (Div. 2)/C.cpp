#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        string s;
        cin >> n >> s;
        map<char,int> mp;
        for (int i=0;i<n;i++){
            mp[s[i]] ++;
        }
        string ans = "";
        for (int i=0;i<n;i++){
            for (char c='a';c<='z';c++){
                if (mp[c]){
                    ans.push_back(c);
                    mp[c] --;
                }
            }
        }
        cout << ans << '\n';
    }
}