#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve(){
    int n, k;
    cin >> n >> k;
    if(k == 0){
        for (int i = 1; i <= n; i++)
            cout << i << ' ';
        cout << '\n';
        return;
    }
    vector<vector<int>> dp(n + 1, vector<int> (k + 1, -1));
    vector<vector<bool>> used(n + 1, vector<bool> (k + 1, 0));
    vector<int> p(n + 1, 0);
    used[0][0] = 1;
    dp[0][0] = 0;
    bool ok = 0;
    int lst = -1;
    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            int add = (i - j) * (n - i);
            for (int s = 0; s + add <= k; s++){
                if(used[j][s]){
                    int ns = s + add;
                    if(!used[i][ns]){
                        used[i][ns] = 1;
                        dp[i][ns] = j;
                    }
                    if(ns == k){
                        ok = 1;
                        lst = i;
                        break;
                    }
                }
            }
            if(ok) break;
        }
        if(ok) break;
    }
    
    if(!ok){
        cout << 0 << '\n';
        return;
    }
    int cur = lst, sum = k;
    while(cur){
        p[cur] = 1;
        int pre = dp[cur][sum];
        int dat = cur - pre;
        int add = dat * (n - cur);
        sum -= add;
        cur = pre;
    }
    int lo = 1, hi = n;
    for (int i = 1; i <= n; i++){
        if(p[i]){
            cout << hi << ' ';
            hi--;
        } else {
            cout << lo << ' ';
            lo++;
        }
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}