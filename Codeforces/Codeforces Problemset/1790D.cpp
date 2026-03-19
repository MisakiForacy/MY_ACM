#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n,x;
        cin >> n;
        map<int,int>mp;
        for (int i=0;i<n;i++){
            cin >> x;
            mp[x] ++;
        }
        int cnt = 0;
        for (auto c:mp){
            int tt = c.second;
            for (int i=0;i<tt;i++){
                int num = c.first;
                mp[num] --;
                while (mp[++num]) mp[num]--;
                cnt ++;
            }
        }
        cout << cnt << '\n';
    }
}