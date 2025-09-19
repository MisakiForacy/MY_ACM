#include <bits/stdc++.h>
using namespace std;
using LL = long long;
// 4 8 15 16 23 42
int main(){
    int n;
    cin >> n;
    map<int,int> b;
    b[4] = 1, b[8] = 2, b[15] = 3, b[16] = 4, b[23] = 5, b[42] = 6;
    vector<int> a(n + 1), vis(n + 1,0);
    int dp[7];
    memset(dp, 0, sizeof(dp));
    for (int i = 1;i <= n;i ++){
        cin >> a[i];
        if (a[i] == 4){
            dp[b[a[i]]] ++;
        } else{
            if (dp[b[a[i]]-1]){
                dp[b[a[i]]-1] --;
                dp[b[a[i]]] ++;
            }
        }
    }
    cout << n - dp[6] * 6 << '\n';
}