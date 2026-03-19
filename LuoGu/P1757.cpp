#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> m >> n;
    map<int,vector<pair<int,int>>> mp;
    int weight,value,group;
    for (int i=0;i<n;i++){
        cin >> weight >> value >> group;
        mp[group].push_back({weight,value});
    }
    int dp[1005];
    for (int i=0;i<=m;i++) dp[i] = 0;
    for (auto [group,goods]:mp){
        for (int i=m;i>=0;i--){
            for (int j=0;j<goods.size();j++){
                if (goods[j].first <= i){
                    dp[i] = max(dp[i],dp[i-goods[j].first]+goods[j].second);
                }
            }
        }
    }
    cout << dp[m] << '\n';
}