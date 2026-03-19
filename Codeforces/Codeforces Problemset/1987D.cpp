#include <bits/stdc++.h>
#define N 5005
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,dp[N],mx;
        cin >> n;
        vector<int>a(n+1),b;
        map<int,int>m;
        for (int i=1;i<=n;i++){
            cin >> a[i];
            m[a[i]]++;
        }
        for (auto s:m){
            b.push_back(s.second);
        }
        memset(dp,0,sizeof(dp));
        for (int i=1;i<int(b.size());i++){
            for (int j=i;j>=b[i];j--){
                dp[j+1] = max(dp[j+1],dp[j-b[i]]+1);
            }
        }
        mx = 0;
        for (int i=0;i<=int(b.size());i++){
            mx = max(mx,dp[i]);
        }
        cout << b.size() - mx << '\n';
    }
}