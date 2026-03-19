#include <bits/stdc++.h>
using namespace std;
const int w[] = {1,2,3,5,10,20};
int main(){
    vector<int> a(6);
    map<int,int> mp;
    for (int i=0;i<6;i++){
        cin >> a[i];
        mp[w[i]] = a[i];
    }
    int dp[1001];
    for (int wi=1;wi<=1000;wi++){
        vector<int> idp(wi+1,0);
        for (int t=0;t<6;t++){
            for (int k=0;k<mp[w[t]];k++){
                for (int j=wi;j>=w[t];j--){
                    idp[j] = max(idp[j],idp[j-w[t]]+w[t]);
                }
            }
        }
        dp[wi] = idp[wi];
    }
    int cnt = 0;
    for (int i=1;i<=1000;i++){
        if (dp[i]==i){
            cnt ++;
        }
    }
    cout << "Total=" << cnt << '\n';
}