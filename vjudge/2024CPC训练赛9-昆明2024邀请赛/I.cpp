#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        string s;
        cin >> s;
        s += ' ';
        vector<int> seg;
        int len = 1;
        for (int i=1;i<s.length();i++){
            if (s[i] == s[i-1]){
                len ++;
            } else{
                seg.push_back(len);
                len = 1;
            }
        }
        s.erase(s.length()-1,1);
        if (seg.size() > 1 && s[0] == s.back()){
            seg[0] += seg.back();
            seg.pop_back();
        }
        if (seg.size() > 1){
            for (int i=0;i<seg.size();i++){
                if (!(seg[i] & 1)){
                    seg[i] --;
                    break;
                }
            }
        }
        int ans = 0;
        for (int i=0;i<seg.size();i++){
            ans += seg[i] / 2;
        }
        cout << ans << '\n';
    }
}