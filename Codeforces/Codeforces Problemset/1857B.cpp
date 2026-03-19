#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int k;
        string s;
        cin >> s;
        int n = s.length();
        vector<int>ans(n + 1,0);
        k = n + 1;
        for (int i=1;i<=n;i++){
            ans[i] = s[i-1]-'0';
            if (ans[i] >= 5){
                k = i;
                for (int j=k-1;j>=0;j--){
                    if (ans[j]!=4){
                        ans[j] ++;
                        k = j+1;
                        goto l;
                    }
                }
            }
        }
        l:{
            for (int i=k;i<=n;i++){
                ans[i] = 0;
            }
        }
        for (int i=(ans[0]?0:1);i<=n;i++){
            cout << ans[i];
        }
        cout << '\n';
    }
}