#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        string s;
        cin >> s;
        LL sum = 0;
        int a2,a3;
        a2 = a3 = 0;
        for (int i=0;i<s.length();i++){
            sum += s[i] - '0';
            if (s[i] == '2') a2 ++;
            if (s[i] == '3') a3 ++;
        }
        sum %= 9;
        if (sum == 0){
            cout << "Yes\n";
        } else{
            int m = 18 - sum;
            vector<int> dp(m+1,0);
            for (int i=0;i<a2;i++){
                for (int j=m;j>=2;j--){
                    dp[j] = max(dp[j],dp[j-2]+2);
                }
            }
            for (int i=0;i<a3;i++){
                for (int j=m;j>=6;j--){
                    dp[j] = max(dp[j],dp[j-6]+6);
                }
            }
            if (dp[m-9]==m-9 || dp[m]==m){
                cout << "Yes\n";
            } else{
                cout << "No\n";
            }
        }
    }
}