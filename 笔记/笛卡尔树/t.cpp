#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int N = 2010;
int n,m;
int a[N][N];
int dp[N][N];
void sto(){
	cin >> n >> m;
	for (int i = 1;i <= m;i++){
		for (int j = 1;j <= n;j++){
			cin >> a[i][j];
			dp[i][j] = 0x3f3f3f3f;
		}
	}
	for (int i = 1;i <= n;i++){
		dp[i][1] = a[i][1];
	}
	for (int j = 2;j <= n;j++){
		for (int i = 1;i <= m;i++){
            int id = i - 1;
            if (id == 0) id = m;
			dp[i][j] = min(dp[i][j-1],dp[id][j-1])+a[i][j];
		}
	}
	for (int i = 1;i <= m;i++){
		for (int j = 1;j <= n;j++){
			cout << dp[i][j] <<" ";
		}
		cout << endl;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T = 1;
//	cin >> T;
	while (T--){
		sto();
	}
	return 0;
}