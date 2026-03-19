#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,ans = 0;
        string s;
        cin >> n >> s;
        for (int i=0;i<n;i++){
            if (s[i]=='y'){
                int cnt = 0;
                int pos = i;
                while (s[++pos]=='b') cnt ++;
                if (cnt >= 2) ans += cnt - 1;
            }
        }
        cout << ans << '\n';
    }
}