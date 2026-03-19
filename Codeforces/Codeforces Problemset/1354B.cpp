#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        string s;
        cin >> s;
        int len = s.length();
        map<char,int> mp;
        int lo,hi;
        lo = hi = 0;
        int mi = len + 1;
        for (hi=0;hi<len;hi++){
            mp[s[hi]] ++;
            if (mp['1']&&mp['2']&&mp['3']){
                while (mp[s[lo]]-1){
                    mp[s[lo]] --;
                    lo ++;
                }
                mi = min(mi,hi-lo+1);
            }
        }
        cout << (mi>len?0:mi) << '\n';
    }
}