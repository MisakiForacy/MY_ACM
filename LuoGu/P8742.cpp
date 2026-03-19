#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int main(){
    int dp[N];
    int temp[N];
    int n,x;
    cin >> n;
    for (int i=1;i<=1e5;i++){
        dp[i] = temp[i] = 0;
    }
    dp[0] = 1;
    for (int i=0;i<n;i++){
        cin >> x;
        for (int j=0;j<=1e5;j++){
            if (dp[j]){
                temp[j+x] = temp[abs(j-x)] = 1;
            }
        }
        for (int j=0;j<=1e5;j++){
            if (temp[j]){
                dp[j] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i=1;i<=1e5;i++){
        if (dp[i]){
            cnt ++;
        }
    }
    cout << cnt << '\n';
}