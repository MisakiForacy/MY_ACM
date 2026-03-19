#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int idx = -1;
        string s;
        cin >> s;
        for (int i=0;i<int(s.length())-1;i++){
            if (s[i]==s[i+1]){
                idx = i;
                break;
            }
        }
        if (idx!=-1){
            string s1 = s.substr(0,idx+1);
            string s2 = s.substr(idx+1,s.length()-idx);
            s = s1 + char((s2[0]+1-'a')%26+'a') + s2;
        } else{
            s = char((s[0]+1-'a')%26+'a') + s;
        }
        cout << s << '\n';
    }
}