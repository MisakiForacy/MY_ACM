#include <bits/stdc++.h>
using namespace std;
bool check(int vis[],int m){
    for (int i=0;i<m;i++){
        if (!vis[i]) return 1;
    }
    return 0;
}
int main(){
    int n,w,x;
    cin >> n >> w;
    map<int,int> mp;
    for (int i=0;i<n;i++){
        cin >> x;
        mp[x] ++;
    }
    vector<int> a;
    for (auto [k,v]:mp){
        a.push_back(v);
    }
    sort(a.begin(),a.end());
    int m = a.size();
    int dp[m+1],vis[m+1];
    int cnt = 0;
    for (int i=0;i<=m;i++) vis[i] = 0;
    for (int i=0;i<=m;i++) dp[i] = 0;
    while (check(vis,m)){
        cnt ++;
        int path[m+1][w+1];
        for (int i=0;i<=m;i++){
            for (int j=0;j<=w;j++){
                path[i][j] = 0;
            }
        }
        for (int i=0;i<m;i++){
            for (int j=w;j>=m;j--){
                if (!vis[i]){
                    dp[j] = dp[j-a[i]] + a[i];
                    path[i][j] = 1;
                }
            }
        }
        int i=m-1,j=w;
		while(i>=0 && j>=0){
			if(path[i][j]){
                vis[i] = 1;
				j -= a[i];
			}
			i --;
		}
    }
    cout << cnt << '\n';
}