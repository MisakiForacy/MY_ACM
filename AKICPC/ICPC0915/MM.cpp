#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        string a,b,c;
        map<string,set<string>> mp;
        for (int i=0;i<n;i++){
            cin >> a >> b >> c;
            if (c=="accepted"){
                mp[b].insert(a);
            }
        }
        int mx = 0;
        string ans;
        for (auto [k,v]:mp){
            if (v.size() > mx){
                mx = v.size();
                ans = v.size();
            }
        }
        cout << ans << '\n';
    }
}