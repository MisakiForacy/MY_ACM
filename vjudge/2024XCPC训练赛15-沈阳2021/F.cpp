#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    string res = "";
    for (int i=1;i<=n;i++){
        string ans = "";
        vector<int> suf(i+1,0);
        int cnt = 0;
        map<char,int> mp;
        for (int j=i;j>=1;j--){
            if (!mp.count(s[j])){
                mp[s[j]] = cnt++;
            }
            suf[j] = mp[s[j]];
        }
        for (int j=1;j<=i;j++){
            ans.push_back('a'+suf[j]);
        }
        res = max(res,ans);
    }
    cout << res << '\n';
}