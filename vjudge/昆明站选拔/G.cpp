#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e6+10;
int dp[N],pre[N];
void f(){
    dp[1] = 1;
    for (int i=2;i<=1e6;i++){
        if (i == sqrt(i)){
            dp[i] ++;
        }
        for (int j=1;j<sqrt(i);j++){
            if (i % j == 0){
                dp[i] += 2;
                if (dp[j] > 3){
                    dp[i] = 4;
                }
            }
            if (dp[i] > 3){
                break;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    f();
    for (int i=1;i<=1e6;i++){
        pre[i] = pre[i-1] + (dp[i]<=3);
    }
    int L,R;
    while (T--){
        cin >> L >> R;
        cout << pre[R] - pre[L-1] << '\n';
    }
}