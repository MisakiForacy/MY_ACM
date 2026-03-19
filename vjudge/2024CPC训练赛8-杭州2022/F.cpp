#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    map<string,int> mp;
    while (T--){
        int n;
        int ok = 1;
        string s;
        cin >> n;
        for (int i=0;i<n;i++){
            cin >> s;
            if (s.find("bie")!=-1 && mp[s] == 0){
                cout << s << '\n';
                mp[s] = 1;
                ok = 0;
            }
        }
        if (ok){
            cout << "Time to play Genshin Impact, Teacher Rice!\n";
        }
    }
}