#include <bits/stdc++.h>
using namespace std;
using LL = long long;
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
        if (n == 1){
            cout << s << '\n';
        } else{
            vector<char> ans;
            for (int i=0;i<n;i++) ans.push_back(s[i]);
            int Max, Min;
            char c1,c2;
            Max = 0, Min = n;
            for (auto [k,v]:mp){
                if (v <= Min){
                    Min = v;
                    c2 = k;
                }
                if (v > Max){
                    Max = v;
                    c1 = k;
                }
            }
            for (int i=0;i<n;i++){
                if (ans[i] == c2){
                    ans[i] = c1;
                    break;
                }
            }
            for (int i=0;i<n;i++){
                cout << ans[i];
            }
            cout << '\n';
        }
    }
}