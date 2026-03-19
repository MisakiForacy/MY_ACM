#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<char,int> mp;
        for (int i=0;i<4*n;i++){
            mp[s[i]] ++;
        }
        int ans = 0;
        ans += min(mp['A'],n);
        ans += min(mp['B'],n);
        ans += min(mp['C'],n);
        ans += min(mp['D'],n);
        cout << ans << '\n';
    }
}